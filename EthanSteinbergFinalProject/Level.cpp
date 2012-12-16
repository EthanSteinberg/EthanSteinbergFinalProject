#include "Level.h"
#include <iostream>

#include <SFML/Graphics.hpp>

Level::Level(Json::Value metadata, const TileSet& tileSet)
{

	Json::Value tiles = metadata["tiles"];
	startX = metadata["startPosition"]["x"].asDouble();
	startY = metadata["startPosition"]["y"].asDouble();


	for (unsigned int columnNum = 0; columnNum < tiles.size(); columnNum++)
	{
		Json::Value column = tiles[columnNum];
		for (unsigned int rowNum = 0; rowNum < column.size(); rowNum++)
		{
			int tileId = column[rowNum].asInt();
			if (tileId != -1)
			{
				sf::Sprite aSprite = tileSet.getTile(tileId);

				aSprite.SetPosition(columnNum * 64, rowNum * 64);
				this->spritesToDraw.push_back(aSprite);

				collisionBoxes.push_back(sf::FloatRect(columnNum, (12 - rowNum), columnNum + 1, (11 - rowNum)));
				
			}
		}
	}

}


Level::Level(const Level& other)
{
	spritesToDraw = other.spritesToDraw;
	startX = other.startX;
	startY = other.startY;

	collisionBoxes = other.collisionBoxes;
}

Level::~Level(void)
{
}


double Level::getStartX() const
{
	return startX;
}

double Level::getStartY() const
{
	return startY;
}

void Level::draw(sf::RenderTarget& target) const
{
	for (unsigned int i =0; i < spritesToDraw.size(); i++)
	{
		const sf::Sprite &sprite = spritesToDraw[i];
		target.Draw(sprite);
	}
}

std::vector<sf::FloatRect> Level::getCollisionBoxes() const
{
	return collisionBoxes;
}