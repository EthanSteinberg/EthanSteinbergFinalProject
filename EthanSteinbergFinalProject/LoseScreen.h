#ifndef LOSE_SCREEN_H_INCLUDED
#define LOSE_SCREEN_H_INCLUDED

#include "State.h"
#include "ResourceLoader.h"


class LoseScreen : public State
{
public:
	LoseScreen(ResourceLoader &resourseLoader);
	~LoseScreen(void);

	virtual void update(double time, StateManager& manager);
	virtual void draw(sf::RenderTarget &target) const;
	virtual void handleEvent(const sf::Event& anEvent,StateManager &manager);

private:
	ResourceLoader &resourceLoader;

	
};

#endif