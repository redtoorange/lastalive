#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

namespace LastAlive
{
	class PositionComponent : public Engine::Component
	{
	public:
		PositionComponent();
		PositionComponent(float x, float y);
		PositionComponent(const sf::Vector2f& p_position);

		void SetPosition(const sf::Vector2f& p_position);
		void SetPositionX(float p_x);
		void SetPositionY(float p_y);

		const sf::Vector2f& GetPosition() const;
		float GetPositionX() const;
		float GetPositionY() const;
		
	private:
		sf::Vector2f m_position;
	};
}
