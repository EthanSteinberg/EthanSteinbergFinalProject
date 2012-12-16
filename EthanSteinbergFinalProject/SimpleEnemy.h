#include "Enemy.h"

class SimpleEnemy : public Enemy
{
public:
	SimpleEnemy(double xPos,double yPos);
	virtual double getX() const ;
	virtual double getY() const;
	virtual double getHeight() const ;
	virtual double getWidth() const ;

	virtual void update(double time, const Level &currentLevel);
	std::string getImageName() const;
private:
	double xPos;
	double yPos;
};