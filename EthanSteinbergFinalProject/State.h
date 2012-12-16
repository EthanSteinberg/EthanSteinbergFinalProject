#pragma once

class StateManager;
namespace sf
{
	class RenderTarget;
	class Event;
}

class State
{
public:
	
	virtual void update(double time, StateManager& manager) = 0;
	virtual void draw(sf::RenderTarget &target) const = 0;
	virtual void handleEvent(const sf::Event& anEvent,StateManager &manager) = 0;

	virtual ~State() {}


};

