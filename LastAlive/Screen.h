#pragma once
#include <vector>

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace Engine
{
	class Entity;

	class Screen
	{
	public:
		Screen();
		virtual ~Screen();

		virtual void update(float p_delta);
		virtual void render(sf::RenderWindow& p_window);
		virtual void handleInput(sf::Event& p_event);

	protected:
		std::vector<Entity*> m_entities;
	};
} //  namespace Engine
