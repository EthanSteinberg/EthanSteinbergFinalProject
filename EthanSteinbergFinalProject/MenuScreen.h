#pragma once
#include "state.h"

#include <SFML/Graphics.hpp>
#include "ResourceLoader.h"

class MenuScreen :
	public State
{
public:
	MenuScreen(ResourceLoader &resourseLoader);
	~MenuScreen(void);

	virtual void update(double time, StateManager& manager);
	virtual void draw(sf::RenderTarget &target) const;
	virtual void handleEvent(const sf::Event& anEvent,StateManager &manager);

private:

	sf::FloatRect enterGameRect;
	sf::FloatRect quitRect;

	ResourceLoader &resourceLoader;

	
};

