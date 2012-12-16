#ifndef GAME_SCREEN_H_INCLUDED
#define GAME_SCREEN_H_INCLUDED

#include "State.h"
#include "ResourceLoader.h"
#include "Player.h"
#include "Level.h"
#include "Missile.h"
#include "Explosion.h"

class GameScreen : public State
{
public:
	GameScreen(ResourceLoader &resourseLoader);
	~GameScreen(void);

	virtual void update(double time, StateManager& manager);
	virtual void draw(sf::RenderTarget &target) const;
	virtual void handleEvent(const sf::Event& anEvent,StateManager &manager);

private:

	const Level* currentLevel;
	Player p;
	ResourceLoader &resourceLoader;

	std::vector<Missile> missiles;
	std::vector<Explosion> explosions;

	sf::View oldView;

	
};

#endif