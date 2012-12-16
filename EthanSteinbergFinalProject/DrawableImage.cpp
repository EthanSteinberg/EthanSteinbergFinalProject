#include "DrawableImage.h"
#include "VectorUtil.h"


DrawableImage::DrawableImage(const sf::Image & b) : base(b)
{
}


DrawableImage::~DrawableImage(void)
{
}

void DrawableImage::draw(sf::RenderTarget& target, double x, double y, double rotation) const
{
	sf::Vector2f position((float)x,(float)y);

	sf::Vector2f heightVec(0,- (float) base.GetHeight()/64);
	
	position -= rotateVector(heightVec,rotation);

	sf::Sprite s;
	s.SetImage(base);
	s.SetPosition(position.x * 64, (12 - position.y) * 64);
	s.SetRotation(float(rotation * 180/PI));

	target.Draw(s);
}


