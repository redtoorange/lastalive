#include "Engine.h"
#include "Screen.h"


namespace Engine
{
	Engine::Engine()
		: m_window({800, 600}, "Game Window"), m_windowWidth(800), m_windowHeight(600)
	{
	}


	Engine::Engine(Uint width, Uint height)
		: m_window({width, height}, "Game Window"), m_windowWidth(width), m_windowHeight(height)
	{
	}


	void Engine::SetCurrentScreen(Screen* p_pScreen)
	{
		m_pCurrentScreen = p_pScreen;
	}

	Screen* Engine::GetCurrentScreen()
	{
		return m_pCurrentScreen;
	}

	void Engine::Start()
	{
		m_running = true;

		while (m_running)
		{
			handleInput();
			update();
			render();
		}

		m_window.close();
	}

	void Engine::update()
	{
		if (m_pCurrentScreen)
			m_pCurrentScreen->Update(m_clock.restart().asSeconds());
	}

	void Engine::render()
	{
		m_window.clear(sf::Color{140, 140, 140});

		if (m_pCurrentScreen)
			m_pCurrentScreen->Render(m_window);

		m_window.display();
	}


	void Engine::handleInput()
	{
		sf::Event events;
		while (m_window.pollEvent(events))
		{
			if (events.type == sf::Event::Closed)
				m_running = false;

			if (m_pCurrentScreen)
				m_pCurrentScreen->HandleInput(events);
		}
	}


	void Engine::SetRunning(bool p_running)
	{
		m_running = p_running;
	}

	bool Engine::IsRunning()
	{
		return m_running;
	}

	Uint Engine::GetWindowWidth()
	{
		return m_windowWidth;
	}

	Uint Engine::GetWindowHeight()
	{
		return m_windowHeight;
	}

	void Engine::SetWindowWidth(Uint p_width)
	{
		m_windowWidth = p_width;
	}

	void Engine::SetWindowHeight(Uint p_height)
	{
		m_windowHeight = p_height;
	}

	Engine::~Engine()
	{
	}
} //  namespace Engine