#pragma once

#include "TileSet.h"
#include <json/value.h>

class Level
{
public:
	Level(Json::Value metadata, const TileSet& tileSet);
	Level(const Level& other);
	~Level(void);

	void draw(sf::RenderTarget & target) const;
	double getStartX() const;
	double getStartY() const;

	std::vector<sf::FloatRect> getCollisionBoxes() const;

private:
	std::vector<sf::Sprite> spritesToDraw;
	double startX;
	double startY;

	std::vector<sf::FloatRect> collisionBoxes;
};

