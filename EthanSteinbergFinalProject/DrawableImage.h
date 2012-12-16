#ifndef DRAWABLE_IMAGE_H_INCLUDED
#define DRAWABLE_IMAGE_H_INCLUDED

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

#endif