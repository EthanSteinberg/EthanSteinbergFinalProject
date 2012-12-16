
#include "WinScreen.h"


WinScreen::WinScreen(ResourceLoader &res) : resourceLoader(res)
{

}

WinScreen::~WinScreen(void)
{

}

void WinScreen::update(double time, StateManager& manager)
{
}

void WinScreen::draw(sf::RenderTarget &target) const
{
	target.Clear(sf::Color::Green);
	target.SetView(target.GetDefaultView());




	sf::String winText("Congradulations, you have won!!\nPlease close the game now.");
	winText.SetPosition(100,768/2-200);
	winText.SetColor(sf::Color::Black);
	winText.SetFont(sf::Font::GetDefaultFont());
	winText.SetSize(40);

	sf::String credits("Credits:\n Nicholas Ireland (AKA Loki_god_of_malice) - Awsome gun drawing\n Daniel Maland (AKA dmaland) - Cool missile graphic\n Random other people - Explosion image, tile set, and flag\n Me - Majestic stick figure");
	credits.SetPosition(50,768/2-100 + 100);
	credits.SetColor(sf::Color::Black);
	credits.SetFont(sf::Font::GetDefaultFont());
	credits.SetSize(22);


	

	target.Draw(winText);
	target.Draw(credits);

}

void WinScreen::handleEvent(const sf::Event& anEvent,StateManager &manager)
{
}


