#pragma once

#include <vector>


namespace sf {
	class RenderWindow;
	class Event;
}

namespace Engine {
	class Entity;
	class BatchRenderer;

	class Screen {
	public:
		Screen() = default;

		virtual ~Screen() = default;

		virtual void Update(float p_delta);

		virtual void Render(sf::RenderWindow& p_window);

		virtual void Render(BatchRenderer& p_batch);

		virtual void HandleInput(sf::Event& p_event);

	protected:
		std::vector<Entity*> m_entities;
	};
} //  namespace Engine
