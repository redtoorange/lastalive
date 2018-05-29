#pragma once

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace Engine
{
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual void update(float p_delta) = 0;
		virtual void render(sf::RenderWindow& p_window) = 0;
		virtual void handleInput(sf::Event& p_event) = 0;

		bool GetsInput() const;
		bool GetsUpdate() const;
		bool GetsRender() const;

	protected:
		bool m_getsInput = true;
		bool m_getsUpdate = true;
		bool m_getsRender = true;
	};
} //  namespace Engine

