#pragma once

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>

class DrawableImage
{
public:
	DrawableImage( const sf::Image & base);
	~DrawableImage(void);

	void draw(sf::RenderTarget& target, double x, double y, double rotation) const;
private:
	const sf::Image &base;

};

