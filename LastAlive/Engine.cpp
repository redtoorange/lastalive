#include "Engine.h"
#include "Scene.h"
#include <iostream>
#include <GL/glew.h>

namespace Engine {
	Engine* Engine::Singleton = nullptr;

	Engine::Engine(sf::RenderWindow* window)
		: m_window(window) {
		if (Singleton)
			std::exception("Attempting to create two copies of a singleton.");
		if (!Singleton)
			Singleton = this;
	}

	Engine* Engine::GetSingleton() {
		return Singleton;
	}

	void Engine::SetCurrentScene(Scene* scene) { m_currentScene = scene; }

	Scene* Engine::GetCurrentScene() {
		return m_currentScene;
	}

	void Engine::Start() {
		m_running = true;;

		while (m_running) {
			handleInput();
			update();
			render();
		}

		m_window->close();
	}

	float total = 0;
	int frames = 0;

	void Engine::update() {
		const auto deltaTime = m_clock.restart().asSeconds();

		frames++;
		total += deltaTime;
		if (total >= 1.0f) {
			total = 0;
			std::cout << "FPS: " << frames << "\n";
			frames = 0;
		}

		if (m_currentScene)
			m_currentScene->Update(deltaTime);
	}

	void Engine::render() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (m_currentScene)
			m_currentScene->Render(m_renderer);

		m_renderer.RenderBatch(m_currentCamera);

		m_window->display();
	}

	void Engine::handleInput() {
		sf::Event events;
		while (m_window->pollEvent(events)) {
			if (events.type == sf::Event::Closed)
				m_running = false;

			if (events.type == sf::Event::KeyPressed)
				if(events.key.code == sf::Keyboard::Escape)
					m_running = false;

			if (m_currentScene)
				m_currentScene->Input(events);
		}
	}

	void Engine::SetRunning(bool p_running) {
		m_running = p_running;
	}

	bool Engine::IsRunning() {
		return m_running;
	}

	void Engine::SetCurrentCamera(Camera* currentCamera) {
		m_currentCamera = currentCamera;
	}

	Camera* Engine::GetCurrentCamera() const {
		return m_currentCamera;
	}

	sf::RenderWindow* Engine::GetCurrentWindow() {
		return m_window;
	}
} //  namespace Engine
