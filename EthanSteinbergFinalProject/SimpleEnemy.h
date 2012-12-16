#ifndef SIMPLE_ENEMY_H_INCLUDED
#define SIMPLE_ENEMY_H_INCLUDED

#include "Enemy.h"

class SimpleEnemy : public Enemy
{
public:
	SimpleEnemy(double xPos,double yPos);
	SimpleEnemy(const SimpleEnemy& other);

	virtual double getX() const ;
	virtual double getY() const;
	virtual double getHeight() const ;
	virtual double getWidth() const ;
	virtual bool isDead() const;

	virtual void kill();


	virtual void update(double time, const Level &currentLevel);
	virtual SimpleEnemy* clone() const;
	std::string getImageName() const;
private:
	double xPos;
	double yPos;
	double xVel;
	bool dead;
};

#endif