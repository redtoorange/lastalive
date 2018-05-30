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

		virtual void Update(float p_delta);
		virtual void Render(sf::RenderWindow& p_window);
		virtual void HandleInput(sf::Event& p_event);

	protected:
		std::vector<Entity*> m_entities;
	};
} //  namespace Engine
