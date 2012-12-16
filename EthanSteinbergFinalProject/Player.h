#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(void);
	~Player(void);

	void setMovingRight(bool moving);
	void setMovingLeft(bool moving);
	void jump();

	void setX(double xPos);
	void setY(double yPos);

	virtual double getX() const;
	virtual double getY() const;
	virtual double getHeight() const;
	virtual double getWidth() const;


	virtual void update(double time, const Level& currentLevel);

	virtual std::string getImageName() const;
private:
	double xPos;
	double yPos;
	double xVel;
	double yVel;
	int movingDirection;
};

