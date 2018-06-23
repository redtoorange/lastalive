#include "Engine.h"
#include "Scene.h"
#include <GL/glew.h>
#include "RenderWindow.hpp"

namespace Engine {
	Engine* Engine::Singleton = nullptr;

	Engine::Engine(RenderWindow* window)
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

		m_window->ShowWindow(true);
		while (m_running) {
			handleInput();
			update();
			render();
		}
		m_window->ShowWindow(false);
	}

	float total = 0;
	int frames = 0;

	void Engine::update() {
		const auto deltaTime = m_clock.UpdateClock();
		SDL_PumpEvents();

		 frames++;
		 total += deltaTime;
		 if (total >= 1.0f) {
		 	total = 0;
			SDL_Log( "FPS: %i \n", frames );
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

		m_window->SwapBuffers();
	}

	void Engine::handleInput() {
		SDL_Event events;
		while(SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT)
				m_running = false;
			if (events.type == SDL_KEYUP && events.key.keysym.sym == SDLK_ESCAPE)
				m_running = false;
			 	
			//
			// 	if (m_currentScene)
			// 		m_currentScene->Input(events);
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

	RenderWindow* Engine::GetCurrentWindow() {
		return m_window;
	}
} //  namespace Engine
