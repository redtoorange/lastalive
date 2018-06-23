#pragma once

// #include <SFML/Graphics.hpp>
#include "BatchRenderer.h"
#include <SDL.h>

namespace Engine {
	class RenderWindow;
	class Screen;
	class Scene;

	class Clock {
	public:
		float GetDeltaTime() const {
			return deltaTime;
		}

		/**
		 * \return deltaTime in seconds
		 */
		float UpdateClock() {
			last = now;
			now = SDL_GetPerformanceCounter();

			deltaTime = (now - last) * 1000.0f / static_cast<float>(SDL_GetPerformanceFrequency());
			deltaTime *= 0.001f;
			return deltaTime;
		}

	private:
		Uint64 now = 0;
		Uint64 last = 0;
		float deltaTime = 0;
	};

	class Engine {
	public:
		static Engine* Singleton;

		Engine(RenderWindow* window);

		virtual ~Engine() = default;

		virtual void Start();

		virtual void SetCurrentScene(Scene* scene);

		virtual Scene* GetCurrentScene();

		virtual void SetCurrentCamera(Camera* currentCamera);

		virtual Camera* GetCurrentCamera() const;

		virtual void SetRunning(bool running);

		virtual bool IsRunning();

		static Engine* GetSingleton();

		RenderWindow* GetCurrentWindow();

	protected:
		virtual void update();

		virtual void render();

		virtual void handleInput();

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		RenderWindow* m_window;
		Scene* m_currentScene;
		Camera* m_currentCamera;

		BatchRenderer m_renderer;
		Clock m_clock;
		bool m_running = false;
	};
} //  namespace Engine
