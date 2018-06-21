#pragma once

#include <SFML/Graphics.hpp>
#include "BatchRenderer.h"

namespace Engine {
	using Uint = unsigned int;

	class Screen;

	class Engine {
	public:
		Engine(sf::RenderWindow* window);

		virtual ~Engine() = default;

		virtual void Start();

		virtual void SetCurrentScreen(Screen* p_pScreen);

		virtual Screen* GetCurrentScreen();

		virtual void SetRunning(bool p_running);

		virtual bool IsRunning();

	protected:
		virtual void update();

		virtual void render();

		virtual void handleInput();

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		sf::RenderWindow* m_pWindow;
		Screen* m_pCurrentScreen;

		BatchRenderer m_renderer;
		sf::Clock m_clock;
		bool m_running = false;
	};
} //  namespace Engine
