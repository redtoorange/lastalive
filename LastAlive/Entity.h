#pragma once
#include <vector>

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace Engine
{
	class Component;

	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		virtual void update(float p_delta);
		virtual void render(sf::RenderWindow& p_window);
		virtual void handleInput(sf::Event& p_event);

	protected:
		std::vector<Component*> m_components;
	};
} // namespace Engine


