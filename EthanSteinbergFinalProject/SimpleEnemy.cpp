#include "SimpleEnemy.h"


SimpleEnemy::SimpleEnemy(double x, double y) : xPos(x), yPos(y)
{
}

SimpleEnemy::SimpleEnemy(const SimpleEnemy& other)
{
	xPos = other.xPos;
	yPos = other.yPos;
}

double SimpleEnemy::getX() const
{
	return xPos;
}

double SimpleEnemy::getY() const
{
	return yPos;
}

double SimpleEnemy::getHeight() const
{
	return 1;
}

double SimpleEnemy::getWidth() const
{
	return 1;
}


void SimpleEnemy::update(double time, const Level &currentLevel)
{
}


std::string SimpleEnemy::getImageName() const
{
	return "ghost";
}

SimpleEnemy *SimpleEnemy::clone() const
{
	return new SimpleEnemy(*this);
}