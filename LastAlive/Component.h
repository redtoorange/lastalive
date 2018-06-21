#pragma once
#include "BatchRenderer.h"

namespace sf {
	class RenderWindow;
	class Event;
}

namespace Engine {
	class Component {
	public:
		Component() = default;

		virtual ~Component() = default;

		virtual void Update(float p_delta);

		virtual void Render(sf::RenderWindow& p_window);

		virtual void Render(BatchRenderer& p_window);

		virtual void HandleInput(sf::Event& p_event);

		bool GetsInput() const;

		bool GetsUpdate() const;

		bool GetsRender() const;

	protected:
		bool m_getsInput = true;
		bool m_getsUpdate = true;
		bool m_getsRender = true;
	};
} //  namespace Engine

