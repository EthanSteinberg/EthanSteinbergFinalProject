#pragma once

#include <json\value.h>
#include <SFML\Graphics\Image.hpp>
#include <SFML\Graphics\Sprite.hpp>

#include <vector>

class TileSet
{
public:
	TileSet(Json::Value metadata, sf::Image& myImage);
	~TileSet(void);

	TileSet(const TileSet& other);

	sf::Sprite getTile(int tileId) const;
private:
	std::vector<sf::Sprite> vectorOfSprites;
	

};

