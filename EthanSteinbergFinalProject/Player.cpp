#include "Player.h"
#include <iostream>
#include <cmath>
Player::Player(void)
{
	xVel = yVel = xPos = yPos = 0;
	movingDirection = 0;
}


Player::~Player(void)
{
}

void Player::setX(double x)
{
	xPos = x;
}

void Player::setY(double y)
{
	yPos = y;
}

 double Player::getX() const
 {
	 return xPos;
 }

 double Player::getY() const
 {
	 return yPos;
 }

 double Player::getHeight() const
 {
	 return 2;
 }
 double Player::getWidth() const
 {
	 return 1;
 }

 bool onFloor = false;
 
 void Player::update(double time, const Level& currentLevel)
 {

	 onFloor = false;

	 yVel -= time * 10;
	  yPos += yVel * time;
	  if (intersectingWithWorld(currentLevel))
	 {
		 onFloor = true;
		 yPos -= yVel * time;
		 yVel = 0;
	  }

	  
	  double xAccel = 0;

	
	 
	 if (onFloor)
	 {
		  if (std::abs(xVel) < 5)
		 {
			 xVel = movingDirection * 5;
		 }

		xVel *= abs(movingDirection);
			

		 xAccel += movingDirection * 2.5;
	 }
	 else
		  if (std::abs(xVel) > 0)
			xAccel -= xVel/ std::abs(xVel) *3.333;

	 xVel += xAccel * time;
	 xVel = std::min(xVel,20.0);

	 xPos += xVel * time;

	 if (intersectingWithWorld(currentLevel))
	 {		 
		 xPos -=xVel * time;
		  xVel = 0;
	 }

	
 }

 std::string Player::getImageName() const
 {
	 return "player";
 }

void Player::jump()
{
	if (onFloor)
	{
		yVel += 10;
		onFloor = !onFloor;

	}
}
void Player::setMovingRight( bool moving)
{
	if (moving)
		movingDirection = 1;
	else
		movingDirection = 0;
}

void Player::setMovingLeft( bool moving)
{
	if (moving)
		movingDirection = -1;
	else
		movingDirection = 0;
}