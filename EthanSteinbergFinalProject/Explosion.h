#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED

#include "GameObject.h"

class Explosion : public GameObject
{
public:
	Explosion(double startX, double startY) {xPos = startX; yPos = startY;timeDrawn=0; dead = false;}
	~Explosion(void){}

	virtual bool isDead() const { return dead;} 
	virtual double getX() const { return xPos;}
	virtual double getY() const { return yPos;}
	virtual double getHeight() const { return 120/64.0;}
	virtual double getWidth() const { return 160/64.0;}


	virtual void update(double time, const Level& currentLevel){timeDrawn+=time; if(timeDrawn >= .25) dead = true;}

	virtual std::string getImageName() const
	{ return "boom";}

private:
	double xPos;
	double yPos;
	bool dead;
	double timeDrawn;
};

#endif