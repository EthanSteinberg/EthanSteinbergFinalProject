#include "MenuScreen.h"
#include <iostream>
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "GameScreen.h"
#include <memory>

MenuScreen::MenuScreen(ResourceLoader &l) : resourceLoader(l)
{

	enterGameRect = sf::FloatRect(171.143f,800 - (491.714f + 107.143f),171.143f+470.000f,800 - (491.714f));
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
		if (enterGameRect.Contains((float) anEvent.MouseButton.X, (float) anEvent.MouseButton.Y))
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
	quitGame.SetPosition(174.714f,800 - (206.429f + 107.143f));

	target.Draw(quitGame);

}

void MenuScreen::update(double time, StateManager& manager)
{
	
}
