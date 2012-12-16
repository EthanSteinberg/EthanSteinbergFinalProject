#include <SFML/System.hpp>
#include <iostream>
#include "StateManager.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "MenuScreen.h"

#include "ResourceLoader.h"
#include "TileSet.h"

int main(int argc, const char* argv[])
{


	ResourceLoader loader(argv[0] + std::string("\\..\\Resources"));
	


	StateManager states;
	states.setState(std::unique_ptr<MenuScreen>(new MenuScreen(loader)));


	sf::RenderWindow app(sf::VideoMode(768, 768, 32), "Ethan Game");
	app.EnableKeyRepeat(false);
	
	sf::Clock clock;
	double timeForSimulation = 0;

	while (app.IsOpened())
	{
		
		sf::Event event;
		while (app.GetEvent(event))
		{
			switch(event.Type)
			{
			case sf::Event::Closed:
				app.Close();
				break;

			default:
				states.handleEvent(event);
			}
				
		}
		timeForSimulation+= clock.GetElapsedTime();
		clock.Reset();

		while (timeForSimulation >= 1.0/60.0)
		{
			states.update(1.0/60.0);
			timeForSimulation -= 1.0/60;
		}

	

		states.draw(app);


		app.Display();

	}



	return 0;
}