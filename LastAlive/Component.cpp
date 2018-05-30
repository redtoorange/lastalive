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

	void Component::Update(float p_delta)
	{
	}

	void Component::Render(sf::RenderWindow& p_window)
	{
	}

	void Component::HandleInput(sf::Event& p_event)
	{
	}
} //  namespace Engine
