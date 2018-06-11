#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

namespace LastAlive
{
	class SpriteComponent : public Engine::Component
	{
	public:
		SpriteComponent();

		virtual void Render(sf::RenderWindow& p_window) override;

		void SetTexture(const sf::Texture& p_texture);

		void SetPosition(const sf::Vector2f& p_position);

		void SetSize(float x, float y);

		void SetScale(float x, float y);

	private:
		sf::Sprite m_sprite;

		sf::Vector2u m_textureSize;
	};
}
