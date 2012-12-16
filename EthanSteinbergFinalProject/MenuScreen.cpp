#include "MenuScreen.h"
#include <iostream>
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include <memory>

MenuScreen::MenuScreen(ResourceLoader &l) : resourceLoader(l)
{

	enterGameRect = sf::FloatRect(171.143,800 - (491.714 + 107.143),171.143+470.000,800 - (491.714));
}


MenuScreen::~MenuScreen(void)
{
}

void MenuScreen::handleEvent(const sf::Event& anEvent, StateManager &manager)
{
	switch(anEvent.Type)
	{
	case sf::Event::MouseButtonPressed:
		std::cout<<anEvent.MouseButton.X<<" "<<anEvent.MouseButton.Y<<std::endl;
		if (enterGameRect.Contains(anEvent.MouseButton.X,anEvent.MouseButton.Y))
		{
			std::cout<<"It is inside the box"<<std::endl;
			manager.setState(std::unique_ptr<GameScreen>(new GameScreen(resourceLoader)));
		}
	}
}

void MenuScreen::draw(sf::RenderTarget &target) const
{
	target.Clear(sf::Color(20,209,0));

	sf::Sprite enterGame;
	enterGame.SetImage(resourceLoader.getImage("gameStartButton"));
	enterGame.SetPosition(enterGameRect.Left,enterGameRect.Top);
	
	target.Draw(enterGame);

	sf::Sprite quitGame;
	quitGame.SetImage(resourceLoader.getImage("menuQuitButton"));
	quitGame.SetPosition(174.714,800 - (206.429 + 107.143));

	target.Draw(quitGame);

}

void MenuScreen::update(double time, StateManager& manager)
{
	
}
