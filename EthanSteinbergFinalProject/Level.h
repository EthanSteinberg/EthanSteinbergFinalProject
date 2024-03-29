#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "TileSet.h"
#include <json/value.h>
#include "DrawableImage.h"

class Enemy;
class ResourceLoader;

class Level
{
public:
	Level(Json::Value metadata, const TileSet& tileSet, const sf::Image &flagImage);
	Level(const Level& other);
	~Level(void);

	void draw(sf::RenderTarget & target, ResourceLoader &loader) const;
	double getStartX() const;
	double getStartY() const;
	double Level::getEndX() const;
	double Level::getEndY() const;

	const std::vector<sf::FloatRect>& getCollisionBoxes() const;

	const std::vector<Enemy*> & getEnemies() const;

	void update(double time) const;

private:
	std::vector<sf::Sprite> spritesToDraw;
	double startX;
	double startY;

	double endX;
	double endY;


	DrawableImage flagImage;

	std::vector<sf::FloatRect> collisionBoxes;

	std::vector<Enemy*> enemyVector;

};

#endif

