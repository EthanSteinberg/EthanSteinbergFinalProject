
#include "LoseScreen.h"


LoseScreen::LoseScreen(ResourceLoader &res) : resourceLoader(res)
{

}

LoseScreen::~LoseScreen(void)
{

}

void LoseScreen::update(double time, StateManager& manager)
{
}

void LoseScreen::draw(sf::RenderTarget &target) const
{
	target.Clear(sf::Color::Red);
	target.SetView(target.GetDefaultView());




	sf::String winText("Sorry, you have lost the game, please restart. \nDon't touch the not-so-friendly ghosts.");
	winText.SetPosition(100,768/2-200);
	winText.SetColor(sf::Color::White);
	winText.SetFont(sf::Font::GetDefaultFont());
	winText.SetSize(30);

	sf::String credits("Art Credits:\n Nicholas Ireland (AKA Loki_god_of_malice) - Awsome gun drawing\n Daniel Maland (AKA dmaland) - Cool missile graphic\n Random other people - Explosion image, tile set, and flag\n Paulina (AKA YourLoveForever) - Interesting pacman ghost \n Me - Majestic stick figure");
	credits.SetPosition(50,768/2-100 + 100);
	credits.SetColor(sf::Color::White);
	credits.SetFont(sf::Font::GetDefaultFont());
	credits.SetSize(22);


	

	target.Draw(winText);
	target.Draw(credits);

}

void LoseScreen::handleEvent(const sf::Event& anEvent,StateManager &manager)
{
}


