#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
	using Uint = unsigned int;
	class Screen;

	class Engine
	{
	public:
		Engine();
		Engine(Uint p_width, Uint p_height);
		virtual ~Engine();

		virtual void Start();

		virtual void SetCurrentScreen(Screen* p_pScreen);
		virtual Screen* GetCurrentScreen();

		virtual void SetRunning(bool p_running);
		virtual bool IsRunning();

		virtual Uint GetWindowWidth();
		virtual Uint GetWindowHeight();

		virtual void SetWindowWidth(Uint p_width);
		virtual void SetWindowHeight(Uint p_height);


	protected:
		sf::RenderWindow m_window;
		sf::Clock m_clock;

		virtual void update();
		virtual void render();
		virtual void handleInput();

	private:
		Uint m_windowWidth;
		Uint m_windowHeight;

		bool m_running = false;
		Screen* m_pCurrentScreen;
	};
} //  namespace Engine