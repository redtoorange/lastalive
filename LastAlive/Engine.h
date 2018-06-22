#pragma once

#include <SFML/Graphics.hpp>
#include "BatchRenderer.h"

namespace Engine {
	using Uint = unsigned int;

	class Screen;
	class Scene;

	class Engine {
	public:
		static Engine* Singleton;

		Engine(sf::RenderWindow* window);

		virtual ~Engine() = default;

		virtual void Start();

		virtual void SetCurrentScene(Scene* scene);

		virtual Scene* GetCurrentScene();

		virtual void SetCurrentCamera(Camera* currentCamera);

		virtual Camera* GetCurrentCamera() const;

		virtual void SetRunning(bool running);

		virtual bool IsRunning();

		static Engine* GetSingleton();

		sf::RenderWindow* GetCurrentWindow();

	protected:
		virtual void update();

		virtual void render();

		virtual void handleInput();

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		sf::RenderWindow* m_window;
		Scene* m_currentScene;
		Camera* m_currentCamera;

		BatchRenderer m_renderer;
		sf::Clock m_clock;
		bool m_running = false;
	};
} //  namespace Engine
