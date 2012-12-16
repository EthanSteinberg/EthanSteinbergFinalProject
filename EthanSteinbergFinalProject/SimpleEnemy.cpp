#include "SimpleEnemy.h"


SimpleEnemy::SimpleEnemy(double x, double y) : xPos(x), yPos(y)
{
	xVel = 5;
	dead = false;
}

SimpleEnemy::SimpleEnemy(const SimpleEnemy& other)
{
	xPos = other.xPos;
	yPos = other.yPos;
	xVel = other.xVel;
	dead = other.dead;
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
	xPos += xVel * time;
	if (intersectingWithWorld(currentLevel))
	{
		xPos -= xVel * time;
		xVel *= -1;
	}
}


std::string SimpleEnemy::getImageName() const
{
	return "ghost";
}

SimpleEnemy *SimpleEnemy::clone() const
{
	return new SimpleEnemy(*this);
}

bool SimpleEnemy::isDead() const
{
	return dead;
}

void SimpleEnemy::kill()
{
	dead = true;
}