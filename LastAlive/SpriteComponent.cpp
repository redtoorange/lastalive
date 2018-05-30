#include "SpriteComponent.h"

namespace LastAlive
{
	SpriteComponent::SpriteComponent()
	{
		m_getsRender = true;
	}

	void SpriteComponent::Render(sf::RenderWindow& p_window)
	{
		p_window.draw(m_sprite);
	}

	void SpriteComponent::SetTexture(const sf::Texture& p_texture)
	{
		m_sprite = sf::Sprite(p_texture);
	}

	void SpriteComponent::SetPosition(const sf::Vector2f& p_position)
	{
		m_sprite.setPosition(p_position);
	}
}
