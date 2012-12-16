#include "TileSet.h"
#include <iostream>

TileSet::TileSet(Json::Value metadata, sf::Image& myImage)
{
	
	std::cout<<metadata.toStyledString()<<std::endl;

	myImage.SetSmooth(false);

	for (auto iter = metadata.begin(); iter != metadata.end() ;iter++)
	{
		std::cout<<(*iter).toStyledString()<<std::endl;

		Json::Value tileData = *iter;

		sf::IntRect rect(tileData["x"].asInt(), tileData["y"].asInt(), tileData["x"].asInt() + 64, tileData["y"].asInt()+64);

		sf::Sprite sprite;
		sprite.SetImage(myImage);
		sprite.SetSubRect(rect);



		vectorOfSprites.emplace_back(std::move(sprite));
	}

}


TileSet::TileSet(const TileSet& other)
{
	vectorOfSprites = other.vectorOfSprites;
}



TileSet::~TileSet(void)
{
}


sf::Sprite TileSet::getTile(int tileId) const
{
	return vectorOfSprites[tileId];
}