#include "GameScreen.h"
#include "Entity.h"

namespace LastAlive
{
	GameScreen::GameScreen()
		: m_player("assets/mario.png")
	{
		m_entities.emplace_back(&m_player);
	}

	GameScreen::~GameScreen()
	{
	}

	void GameScreen::Update(float p_delta)
	{
		Screen::Update(p_delta);
	}

	void GameScreen::Render(sf::RenderWindow& p_window)
	{
		Screen::Render(p_window);
	}
}
