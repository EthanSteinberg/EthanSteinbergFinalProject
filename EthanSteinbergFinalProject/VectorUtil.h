#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <array>

inline sf::Vector2f rotateVector(sf::Vector2f in, double rad)
{
	return sf::Vector2f((float) (in.x * std::cos(rad) - in.y * std::sin(rad)), (float) (in.y * std::cos(rad) + in.x * std::sin(rad)));
}


inline std::array<sf::Vector2f,4> getCorners(sf::FloatRect rectangle)
{
	std::array<sf::Vector2f,4> result;
	result[0] = sf::Vector2f(0,0);
	result[1] = sf::Vector2f(0,-rectangle.GetHeight());
	result[2] = sf::Vector2f(rectangle.GetWidth(), 0);
	result[3] = sf::Vector2f(rectangle.GetWidth(),-rectangle.GetHeight());

	return result;
}



inline bool getLeastX(const sf::Vector2f&a, const sf::Vector2f&b) { 
		return a.x < b.x;
}

inline bool getLeastY(const sf::Vector2f&a, const sf::Vector2f&b) { 
	return a.y < b.y;
}


inline bool colliding(sf::FloatRect first, sf::FloatRect second, double angleOfSecond)
{

	std::array<sf::Vector2f,4> secondBase = getCorners(second);

	for(unsigned int i =0; i < secondBase.size(); i++)
	{
		sf::Vector2f& side = secondBase[i];
		side = rotateVector(side,angleOfSecond) + sf::Vector2f(second.Left,second.Bottom);
	}

	double minXForFirst = first.Left;
	double maxXForFirst = first.Right;

	double minXForSecond = std::min_element(std::begin(secondBase),std::end(secondBase), getLeastX)->x;

	double maxXForSecond = std::max_element(std::begin(secondBase),std::end(secondBase), getLeastX)->x;



	if (!((minXForFirst < maxXForSecond && minXForFirst > minXForSecond) || (minXForSecond < maxXForFirst && minXForSecond > minXForFirst)))
	{
		
		return false;
	}


	double minYForFirst = first.Bottom;
	double maxYForFirst = first.Top;

	double minYForSecond = std::min_element(std::begin(secondBase),std::end(secondBase), getLeastY)->y;

	double maxYForSecond = std::max_element(std::begin(secondBase),std::end(secondBase), getLeastY)->y;




	if (!((minYForFirst < maxYForSecond && minYForFirst > minYForSecond) || (minYForSecond < maxYForFirst && minYForSecond > minYForFirst)))
	{
	
		return false;
	}


	

	return true;



}

inline bool MyRectIntersection(sf::FloatRect one, sf::FloatRect other)
{
	sf::FloatRect Overlapping(std::max(one.Left,   other.Left),
                     std::min(one.Top,    other.Top),
                     std::min(one.Right,  other.Right),
                     std::max(one.Bottom, other.Bottom));

			if ((  Overlapping.Right > Overlapping.Left ) && (  Overlapping.Top  >  Overlapping.Bottom))
				return true;
			return false;
}


const double PI = 3.14;
