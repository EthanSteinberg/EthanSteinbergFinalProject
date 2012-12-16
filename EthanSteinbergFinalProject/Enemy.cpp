#include "Enemy.h"

#include "SimpleEnemy.h"

Enemy* Enemy::createEnemy(std::string type, double x, double y)
{
	if (type == "simple")
		return new SimpleEnemy(x,y);
	else
		return NULL; // No such type
}