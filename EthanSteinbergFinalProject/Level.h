#pragma once

#include "TileSet.h"
#include <json/value.h>
#include "DrawableImage.h"



class Level
{
public:
	Level(Json::Value metadata, const TileSet& tileSet, const sf::Image &flagImage);
	Level(const Level& other);
	~Level(void);

	void draw(sf::RenderTarget & target) const;
	double getStartX() const;
	double getStartY() const;
	double Level::getEndX() const;
	double Level::getEndY() const;

	const std::vector<sf::FloatRect>& getCollisionBoxes() const;

private:
	std::vector<sf::Sprite> spritesToDraw;
	double startX;
	double startY;

	double endX;
	double endY;


	DrawableImage flagImage;

	std::vector<sf::FloatRect> collisionBoxes;
};

