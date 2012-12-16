#pragma once

#include <memory>
#include "State.h"

namespace sf
{
	class RenderTarget;
	class Event;
}


class StateManager
{
public:
	void setState(std::unique_ptr<State> && newState);
	void update(double time);
	void draw(sf::RenderTarget& target) const;
	void handleEvent(const sf::Event &anEvent);

private:
	std::unique_ptr<State> myState;
};