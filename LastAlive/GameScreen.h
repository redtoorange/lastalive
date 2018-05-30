#pragma once
#include "Screen.h"
#include "PlayerCharacter.h"

namespace LastAlive
{
	class GameScreen : public Engine::Screen
	{
	public:
		GameScreen();
		virtual ~GameScreen() override;


		virtual void Update(float p_delta) override;
		virtual void Render(sf::RenderWindow& p_window) override;

	private:
		PlayerCharacter m_player;
	};
}
