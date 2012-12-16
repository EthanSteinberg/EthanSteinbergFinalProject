#ifndef WIN_SCREEN_H_INCLUDED
#define WIN_SCREEN_H_INCLUDED

#include "State.h"
#include "ResourceLoader.h"


class WinScreen : public State
{
public:
	WinScreen(ResourceLoader &resourseLoader);
	~WinScreen(void);

	virtual void update(double time, StateManager& manager);
	virtual void draw(sf::RenderTarget &target) const;
	virtual void handleEvent(const sf::Event& anEvent,StateManager &manager);

private:
	ResourceLoader &resourceLoader;

	
};

#endif
