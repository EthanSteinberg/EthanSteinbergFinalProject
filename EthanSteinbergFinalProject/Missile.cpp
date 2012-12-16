#include "Missile.h"


Missile::Missile(double startX, double startY, double angle)
{
	this->xPos = startX;
	this->yPos = startY;
	this->angle = angle;
	dead = false;
}


const double speed = 10;

Missile::~Missile(void)
{
}


 double Missile::getX() const
 {
	 return xPos;
 }

 double Missile::getY() const
 {
	 return yPos;
 }

 double Missile::getHeight() const
 {
	 return 30/64.0f;
 }
 double Missile::getWidth() const
 {
	 return 108/64.0f;
 }

 double Missile::getRotation() const
 {
	 return angle;
 }


 void Missile::update(double time, const Level& currentLevel)
 {
	 if (dead)
		 return;

	double distance = speed * time;

	xPos += distance * cos(angle);
	yPos += distance * sin(angle);

	
	sf::FloatRect myRect = getCollisionBox();





	for (unsigned int i = 0; i <  currentLevel.getCollisionBoxes().size(); i++)
	{
		sf::FloatRect boxes = currentLevel.getCollisionBoxes()[i];
		if (colliding(boxes,myRect,angle))
		{
	
			dead = true;
			break;
		}
	}
	
 }

 std::string Missile::getImageName() const
 {
	 return "missile";
 }
