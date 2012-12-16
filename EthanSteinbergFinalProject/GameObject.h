#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "ResourceLoader.h"
#include <cmath>

#include "DrawableImage.h"

#include "VectorUtil.h"

class GameObject
{
public:
	virtual ~GameObject(void){}

	virtual double getX() const = 0;
	virtual double getY() const = 0;
	virtual double getHeight() const = 0;
	virtual double getWidth() const = 0;
	virtual double getRotation() const
	{
		return 0;
	}


	virtual bool isDead() const { return true;}


	virtual void update(double time, const Level &currentLevel) =0;

	virtual std::string getImageName() const = 0;

	void draw(sf::RenderTarget &target, ResourceLoader &resources) const
	{
		const sf::Image& image = resources.getImage(getImageName());


		DrawableImage im(image);
		im.draw(target,getX(),getY(),getRotation());

	}

	void drawCollisionOutline(sf::RenderTarget &target) const
	{


		sf::Shape rectangle = sf::Shape::Rectangle(getX() * 64,(12 - getY()) * 64, (getX() + getWidth()) * 64, (12 - getY() - getHeight()) * 64,sf::Color(0,0,0,0),2,sf::Color::Green);
		target.Draw(rectangle);
	}

	sf::FloatRect getCollisionBox() const
	{
		return sf::FloatRect(getX(), getY() + getHeight(), getX()  + getWidth(), getY());
	}

	bool intersectingWithWorld(const Level& currentLevel) const
	{
		auto boxes = currentLevel.getCollisionBoxes();

	    sf::FloatRect myBox = getCollisionBox();

		for (unsigned int  i =0; i < boxes.size(); i++)
		{
			const sf::FloatRect& other = boxes[i];

	    
			sf::FloatRect Overlapping(std::max(other.Left,   myBox.Left),
                     std::min(other.Top,    myBox.Top),
                     std::min(other.Right,  myBox.Right),
                     std::max(other.Bottom, myBox.Bottom));

			if ((  Overlapping.Right > Overlapping.Left ) && (  Overlapping.Top  >  Overlapping.Bottom))
				return true;
	
		
		}

		return false;
	}
	


};

