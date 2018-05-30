#include "Component.h"

namespace Engine
{
	bool Component::GetsInput() const
	{
		return m_getsInput;
	}

	bool Component::GetsUpdate() const
	{
		return m_getsUpdate;
	}

	bool Component::GetsRender() const
	{
		return m_getsRender;
	}

	void Component::update(float p_delta)
	{
	}

	void Component::render(sf::RenderWindow& p_window)
	{
	}

	void Component::handleInput(sf::Event& p_event)
	{
	}
} //  namespace Engine
