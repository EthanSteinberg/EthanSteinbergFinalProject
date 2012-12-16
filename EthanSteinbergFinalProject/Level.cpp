#include "Level.h"
#include <iostream>

#include <SFML/Graphics.hpp>


#include "DrawableImage.h"

Level::Level(Json::Value metadata, const TileSet& tileSet, const sf::Image &flag) : flagImage(flag)
{

	Json::Value tiles = metadata["tiles"];
	startX = metadata["startPosition"]["x"].asDouble();
	startY = metadata["startPosition"]["y"].asDouble();
	endX = metadata["endPosition"]["x"].asDouble();
	endY = metadata["endPosition"]["y"].asDouble();


	

	

	std::cout<<endX<<" flag "<<endY<<std::endl;
	

	for (unsigned int columnNum = 0; columnNum < tiles.size(); columnNum++)
	{
		Json::Value column = tiles[columnNum];
		for (unsigned int rowNum = 0; rowNum < column.size(); rowNum++)
		{
			int tileId = column[rowNum].asInt();
			if (tileId != -1)
			{
				sf::Sprite aSprite = tileSet.getTile(tileId);

				aSprite.SetPosition( columnNum * 64.0f, rowNum * 64.0f);
				this->spritesToDraw.push_back(aSprite);

				collisionBoxes.push_back(sf::FloatRect( (float) columnNum, (float) (12 - rowNum),  (float) columnNum + 1, (float) (11 - rowNum)));
				
			}
		}
	}



}


Level::Level(const Level& other) : flagImage(other.flagImage)
{
	spritesToDraw = other.spritesToDraw;
	startX = other.startX;
	startY = other.startY;
	endX = other.endX;
	endY = other.endY;

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

double Level::getEndX() const
{
	return endX;
}

double Level::getEndY() const
{
	return endY;
}

void Level::draw(sf::RenderTarget& target) const
{


	for (unsigned int i =0; i < spritesToDraw.size(); i++)
	{
		const sf::Sprite &sprite = spritesToDraw[i];
		target.Draw(sprite);
	}

	flagImage.draw(target,endX,endY,0);

	
}



const std::vector<sf::FloatRect>& Level::getCollisionBoxes() const
{
	return collisionBoxes;
}