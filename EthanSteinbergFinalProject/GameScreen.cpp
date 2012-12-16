#include "GameScreen.h"
#include <SFML/Graphics.hpp>

#include "Player.h"
#include <cmath>
#include <iostream>


#include "VectorUtil.h"

GameScreen::GameScreen(ResourceLoader& loader)  : resourceLoader(loader)
{
	currentLevel = &resourceLoader.getLevel("testLevel");
	p.setX(currentLevel->getStartX());
	p.setY(currentLevel->getStartY());
}


GameScreen::~GameScreen(void)
{
}


bool shouldKillMissile(const Missile& mil)
{
		return mil.isDead();
}


bool shouldKillExplosion(const Explosion& mil)
{
		return mil.isDead();
}

double rotation = 0;
void GameScreen::update(double time, StateManager& manager) 
{
	p.update(time,*currentLevel);
	
	for ( unsigned int i =0; i < missiles.size(); i++)
	{
		Missile &mis  = missiles[i];
		mis.update(time,*currentLevel);

	}

	for ( unsigned int i =0; i < missiles.size(); i++)
	{
		const Missile &mis  = missiles[i];
		if (mis.isDead())
		{
			sf::Vector2f explosionPosition = sf::Vector2f((float) mis.getX(), (float) mis.getY()) + rotateVector(sf::Vector2f( (float) mis.getWidth()/2, (float) mis.getHeight()/2),mis.getRotation()) - sf::Vector2f(160/64.0f * .5f, 120/64.0f * .5f)  ;
			explosions.push_back(Explosion(explosionPosition.x,explosionPosition.y));
		}

	}

		
	missiles.erase(std::remove_if(missiles.begin(),missiles.end(),shouldKillMissile),missiles.end());
	

	for ( unsigned int i =0; i < explosions.size(); i++)
	{
		Explosion &mis = explosions[i];
		mis.update(time,*currentLevel);
	}


		explosions.erase(std::remove_if(explosions.begin(),explosions.end(),shouldKillExplosion),explosions.end());
	
}



void GameScreen::draw(sf::RenderTarget &target) const 
{
	



	target.Clear(sf::Color(135,206,250));
	target.SetView(sf::View(sf::Vector2f( (float) p.getX() * 64, (float) (10 - p.getY()) * 64),sf::Vector2f(768/2,768/2)));


	

	for ( unsigned int i =0; i < missiles.size(); i++)
	{
		const Missile &mis  = missiles[i];
		mis.draw(target,resourceLoader);
	}

	for ( unsigned int i =0; i < explosions.size(); i++)
	{
		const Explosion &mis  = explosions[i];
		mis.draw(target,resourceLoader);
	}
	

	
	currentLevel->draw(target);

	for ( unsigned int i =0; i < currentLevel->getCollisionBoxes().size(); i++)
	{
		sf::FloatRect rect = currentLevel->getCollisionBoxes()[i];
		sf::Shape rectangle = sf::Shape::Rectangle(rect.Left*64,(12 - rect.Bottom) * 64, rect.Right *64,(12 - rect.Top) * 64,sf::Color(0,0,0,0),2,sf::Color::Black);
		target.Draw(rectangle);
	}


	
	p.draw(target,resourceLoader);
	p.drawCollisionOutline(target);

	DrawableImage gun(resourceLoader.getImage("gun"));


	double rad = rotation * PI/180;

	sf::Vector2f offsetToHandle = (resourceLoader.getImageSpecialData("gun").find("offsetToGrip")->second)/64.0f;
	
	sf::Vector2f offsetToHand = (resourceLoader.getImageSpecialData("player").find("offsetToHand")->second) / 64.0f;

	sf::Vector2f rotatedOffsetToHandle = rotateVector(offsetToHandle,rad);

	sf::Vector2f amountToMoveImage = offsetToHand - rotatedOffsetToHandle;

	sf::Vector2f totalPosition = amountToMoveImage + sf::Vector2f((float) p.getX(),(float) p.getY());
	

	gun.draw(target,totalPosition.x,totalPosition.y,rad);

}


//Brute force this baby. I give up on vector math
double findAngle(sf::Vector2f target, sf::Vector2f offset)
{
	for (double angle = -PI; angle <  PI; angle += 1)
	{
		sf::Vector2f rotated = rotateVector(offset,angle);
		sf::Vector2f diff = target - rotated;
		double newAngle = atan2(diff.y, diff.x);

		if (std::abs(newAngle - angle) < 1)
		{
			return newAngle;
		}
	}

	return std::log(-1.0); //No such angle

}

	


void GameScreen::handleEvent(const sf::Event& anEvent,StateManager &manager)
{
	switch(anEvent.Type)
	{
	case sf::Event::KeyPressed:
		switch(anEvent.Key.Code)
		{
		case sf::Key::A:
			p.setMovingLeft(true);
			break;
		case sf::Key::S:
			p.setMovingRight(true);
			break;
		case sf::Key::W:
			p.jump();
			break;
		case sf::Key::R:
			
			break;
		}
	break;

	case sf::Event::KeyReleased:
		switch(anEvent.Key.Code)
		{
		case sf::Key::A:
			p.setMovingLeft(false);
			break;
		case sf::Key::S:
			p.setMovingRight(false);
			break;
		}
		
		break;
	case sf::Event::MouseMoved:
		{
			int mouseX = anEvent.MouseMove.X;
			int mouseY = anEvent.MouseMove.Y;
			
			double realX = (mouseX - 768/2)/64.0 + p.getX();
			double realY = (768/2 - mouseY)/64.0 + p.getY() +2;


		

			sf::Vector2f offsetToHand = (resourceLoader.getImageSpecialData("player").find("offsetToHand")->second) / 64.0f;
			//std::cout<<realX<<" "<<realY<<std::endl;

			offsetToHand += sf::Vector2f((float) p.getX(), (float) p.getY());

			sf::Vector2f realVec((float)realX,(float)realY);
			sf::Vector2f distance = realVec - offsetToHand;

			sf::Vector2f mousePosition((float)realX, (float) realY);

			
			double rad = findAngle(mousePosition - offsetToHand, ( (resourceLoader.getImageSpecialData("gun").find("offsetToStartOfBarrel")->second) / 64.0f) - (resourceLoader.getImageSpecialData("gun").find("offsetToGrip")->second) / 64.0f);

			//std::cout<<(rad * 180/pi)<<std::endl;
			rotation = rad*180/PI;
		}
		break;

	case sf::Event::MouseButtonPressed:
		{

			double rad = rotation * PI/180;

			sf::Vector2f offsetToHandle = (resourceLoader.getImageSpecialData("gun").find("offsetToGrip")->second)/64.0f;
	

			sf::Vector2f offsetToHand = (resourceLoader.getImageSpecialData("player").find("offsetToHand")->second) / 64.0f;

			sf::Vector2f offsetToEndOfBarrel =  (resourceLoader.getImageSpecialData("gun").find("offsetToEndOfBarrel")->second) / 64.0f;

			sf::Vector2f offsetToEnd = (resourceLoader.getImageSpecialData("missile").find("offsetToEnd")->second) / 64.0f;

			sf::Vector2f missilePosition = sf::Vector2f((float) p.getX(), (float) p.getY()) + offsetToHand + rotateVector(offsetToEndOfBarrel - offsetToHandle,rad) -rotateVector(offsetToEnd,rad);
		
			if (!_isnan(rad))
				missiles.push_back(Missile(missilePosition.x,missilePosition.y,rad));
	
			
		}
		break;
	}




}