#include "Engine.h"
#include "Screen.h"
#include <iostream>


namespace Engine
{
	Engine::Engine(sf::RenderWindow* window)
		: m_window(window), m_mesh(), m_instance(&m_mesh)
	{
		renderer = new ModelRenderer();
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
		m_instance.SetShader(renderer->GetDefaultShader());
		m_running = true;
		
		m_window->setVerticalSyncEnabled(true);

		while (m_running)
		{
			handleInput();
			update();
			render();
		}

		m_window->close();
	}

	void Engine::update()
	{
		float delta = m_clock.restart().asSeconds();
		if (m_pCurrentScreen)
			m_pCurrentScreen->Update(delta);

		auto rot = m_instance.GetRotation();
		rot.x += delta;
		m_instance.SetRotation(rot);

		renderer->Render(&m_instance);
	}

	void Engine::render()
	{
		m_window->clear(sf::Color{140, 140, 140});


		if (m_pCurrentScreen)
			m_pCurrentScreen->Render(*m_window);

		renderer->Draw();

		m_window->display();
	}


	void Engine::handleInput()
	{
		sf::Event events;
		while (m_window->pollEvent(events))
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

//	Uint Engine::GetWindowWidth()
//	{
//		return m_windowWidth;
//	}
//
//	Uint Engine::GetWindowHeight()
//	{
//		return m_windowHeight;
//	}
//
//	void Engine::SetWindowWidth(Uint p_width)
//	{
//		m_windowWidth = p_width;
//	}
//
//	void Engine::SetWindowHeight(Uint p_height)
//	{
//		m_windowHeight = p_height;
//	}

	Engine::~Engine()
	{
		delete renderer;
	}
} //  namespace Engine
