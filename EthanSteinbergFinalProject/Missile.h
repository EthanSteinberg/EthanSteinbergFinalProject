#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

#include "GameObject.h"

class Missile : public GameObject
{
public:
	Missile(double startX, double startY, double angle);
	~Missile(void);

	virtual bool isDead() const { return dead;} 
	virtual double getX() const;
	virtual double getY() const;
	virtual double getHeight() const;
	virtual double getWidth() const;
	virtual double getRotation() const;

	virtual void update(double time, const Level& currentLevel);

	virtual std::string getImageName() const;

private:
	double xPos;
	double yPos;
	double angle;
	bool dead;
};

#endif