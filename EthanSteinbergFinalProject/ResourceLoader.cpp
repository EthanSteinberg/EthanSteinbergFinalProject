#include "ResourceLoader.h"
#include <iostream>

#include <fstream>



#include <tuple>

#include <json\reader.h>
#include <json\writer.h>

ResourceLoader::ResourceLoader(std::string directory)
{

	
	std::string pathToDirectory(directory);
	

	std::ifstream indexFile(pathToDirectory  + "\\index.json");

	

	Json::Value root;
	Json::Reader reader;

	bool parsingSuccessful = reader.parse(indexFile, root);
	if (!parsingSuccessful)
		std::cout<< "Parsing of JSON failed"<<std::endl;


	
	
	indexFile.close();

	std::ofstream outIndexFile(pathToDirectory + "\\index.json");
	outIndexFile.clear();

	Json::StyledStreamWriter writer;
	writer.write(outIndexFile,root);
	outIndexFile.close();

	

	Json::Value images = root["image"];

	for (auto iter = images.begin(); iter != images.end(); iter++)
	{
		Json::Value currentImage = *iter;
		
		std::string pathToImage = pathToDirectory +"\\" + currentImage["location"].asString();
	


		imageMap[currentImage["name"].asString()] = sf::Image();
		
		imageMap[currentImage["name"].asString()].LoadFromFile(pathToImage);

		
		Json::Value locations = currentImage["info"];

		std::map<std::string, sf::Vector2f> locationsOfThings;

		for (auto iter2 = locations.begin(); iter2 != locations.end() ; iter2++)
		{
			
			std::string name = iter2.memberName();

			sf::Vector2f vec((*iter2)[0].asFloat(),(*iter2)[1].asFloat());
			locationsOfThings.insert(std::make_pair(name,vec));
		}

		this->imageSpecialDataLocations[currentImage["name"].asString()] =  locationsOfThings;

	}

	
	
	Json::Value tileSets = root["tileset"];
	for (auto iter = tileSets.begin(); iter != tileSets.end(); iter++)
	{
		Json::Value currentTileSet = *iter;
		
		
		std::string metadataFile( pathToDirectory + "\\" +  currentTileSet["metadata"].asString());

		Json::Value metadata;
		reader.parse(std::ifstream(metadataFile),metadata);

		//std::string pathToImage = pathToDirectory + "\\" + currentTileSet["image"].asString();
		std::string name = currentTileSet["image"].asString();
		
		tileSetMap.insert(std::make_pair(currentTileSet["name"].asString(),TileSet(metadata, imageMap.find(name)->second)));

	}


	Json::Value levels = root["level"];
	for (auto iter = levels.begin(); iter != levels.end(); iter++)
	{
		Json::Value currentLevel = *iter;
		
		
		std::string metadataFile( pathToDirectory + "\\" +  currentLevel["tiles"].asString());

		Json::Value metadata;
		reader.parse(std::ifstream(metadataFile),metadata);

		std::string tileSet = currentLevel["tileset"].asString();
		

		levelMap.insert(std::make_pair(currentLevel["name"].asString(),Level(metadata, getTileSet(tileSet),getImage("flag"))));

	}

}


const sf::Image& ResourceLoader::getImage(std::string name) const
{
	return imageMap.find(name)->second;
}

const TileSet& ResourceLoader::getTileSet(std::string name) const
{
	return tileSetMap.find(name)->second;
}

const Level& ResourceLoader::getLevel(std::string name) const
{
	return levelMap.find(name)->second;
}

ResourceLoader::~ResourceLoader(void)
{
}

const std::map<std::string, sf::Vector2f>& ResourceLoader::getImageSpecialData(std::string name) const
{
	return imageSpecialDataLocations.find(name)->second;
}