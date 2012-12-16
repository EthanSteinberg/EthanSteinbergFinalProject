#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "GameObject.h"

class Enemy : public GameObject
{
public:
	virtual Enemy* clone() const = 0;
	virtual void kill() = 0;

	static Enemy* createEnemy(std::string type, double x, double y);
};

#endif