#pragma once

#include <string>
#include <map>
#include <SFML/Graphics/Image.hpp>

#include "TileSet.h"
#include "Level.h"

class ResourceLoader
{
public:
	ResourceLoader(std::string pathToDirectory);

	~ResourceLoader(void);


	const sf::Image& getImage(std::string name) const;
	const TileSet& getTileSet(std::string name) const;
	const Level& getLevel(std::string name) const;
	const std::map<std::string, sf::Vector2f>& getImageSpecialData(std::string name) const;

private:
	std::map<std::string,sf::Image> imageMap;
	std::map<std::string, TileSet> tileSetMap;
	std::map<std::string, Level> levelMap;
	std::map< std::string, std::map<std::string, sf::Vector2f>> imageSpecialDataLocations;



};

