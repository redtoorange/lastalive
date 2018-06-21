#include "PositionComponent.h"

namespace LastAlive
{
	PositionComponent::PositionComponent()
		: PositionComponent(sf::Vector2f{0, 0})
	{
	}

	PositionComponent::PositionComponent(float x, float y)
		: PositionComponent(sf::Vector2f{x, y})
	{
	}

	PositionComponent::PositionComponent(const sf::Vector2f& p_position)
		: m_position(p_position)
	{
		m_getsUpdate = false;
		m_getsInput = false;
		m_getsRender = false;
	}

	void PositionComponent::SetPosition(const sf::Vector2f& p_position)
	{
		m_position = p_position;
	}

	void PositionComponent::SetPositionX(float p_x)
	{
		m_position.x = p_x;
	}

	void PositionComponent::SetPositionY(float p_y)
	{
		m_position.y = p_y;
	}

	const sf::Vector2f& PositionComponent::GetPosition() const
	{
		return m_position;
	}

	float PositionComponent::GetPositionX() const
	{
		return m_position.x;
	}

	float PositionComponent::GetPositionY() const
	{
		return m_position.y;
	}
}
