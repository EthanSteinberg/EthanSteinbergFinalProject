#include "StateManager.h"
#include "State.h"



void StateManager::setState(std::unique_ptr<State> && newState)
{
	myState = std::move(newState);
}

void StateManager::update(double time)
{
	myState->update(time,*this);
}

void StateManager::draw(sf::RenderTarget& target) const
{
	myState->draw(target);
}

void StateManager::handleEvent(const sf::Event &anEvent) 
{
	myState->handleEvent(anEvent,*this);
}