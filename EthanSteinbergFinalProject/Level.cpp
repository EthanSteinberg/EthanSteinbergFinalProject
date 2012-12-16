#include "Level.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Enemy.h"

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

	Json::Value enemies = metadata["enemies"];

	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		Json::Value enemy = enemies[i];

		enemyVector.push_back(Enemy::createEnemy(enemy["type"].asString(), enemy["x"].asDouble(), enemy["y"].asDouble()));
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

	for (unsigned int i = 0; i < other.enemyVector.size(); i++)
	{
		enemyVector.push_back(other.enemyVector[i]->clone());
	}
}

Level::~Level(void)
{
	for (unsigned int i =0 ; i < enemyVector.size(); i++)
	{
		delete enemyVector[i];
	}
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

void Level::draw(sf::RenderTarget& target, ResourceLoader& loader) const
{


	for (unsigned int i =0; i < spritesToDraw.size(); i++)
	{
		const sf::Sprite &sprite = spritesToDraw[i];
		target.Draw(sprite);
	}

	flagImage.draw(target,endX,endY,0);

	for (unsigned int i = 0; i < enemyVector.size(); i++)
	{
		enemyVector[i]->draw(target,loader);
		std::cout<<enemyVector[i]->getX()<<std::endl;
	}

	
}



const std::vector<sf::FloatRect>& Level::getCollisionBoxes() const
{
	return collisionBoxes;
}

const std::vector<Enemy*>& Level::getEnemies() const
{
	return enemyVector;
}