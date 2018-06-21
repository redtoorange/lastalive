#include "Engine.h"
#include "Screen.h"
#include <iostream>
#include <GL/glew.h>

namespace Engine {
	Engine::Engine(sf::RenderWindow* window)
		: m_pWindow(window) { }

	void Engine::SetCurrentScreen(Screen* p_pScreen) {
		m_pCurrentScreen = p_pScreen;
	}

	Screen* Engine::GetCurrentScreen() {
		return m_pCurrentScreen;
	}

	void Engine::Start() {
		m_running = true;

		// m_pWindow->setVerticalSyncEnabled(true);

		while (m_running) {
			handleInput();
			update();
			render();
		}

		m_pWindow->close();
	}

	float total = 0;
	int frames = 0;

	void Engine::update() {
		float delta = m_clock.restart().asSeconds();

		frames++;
		total += delta;
		if(total >= 1.0f) {
			total = 0;
			std::cout << "FPS: " << frames << "\n";
			frames = 0;
		}

		if (m_pCurrentScreen)
			m_pCurrentScreen->Update(delta);
	}

	void Engine::render() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (m_pCurrentScreen) {
			m_pCurrentScreen->Render(m_renderer);
		}

		m_renderer.RenderBatch();

		m_pWindow->display();
	}

	void Engine::handleInput() {
		sf::Event events;
		while (m_pWindow->pollEvent(events)) {
			if (events.type == sf::Event::Closed)
				m_running = false;

			if (m_pCurrentScreen)
				m_pCurrentScreen->HandleInput(events);
		}
	}

	void Engine::SetRunning(bool p_running) {
		m_running = p_running;
	}

	bool Engine::IsRunning() {
		return m_running;
	}
} //  namespace Engine
