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
		m_textureSize = p_texture.getSize();
	}

	void SpriteComponent::SetPosition(const sf::Vector2f& p_position)
	{
		m_sprite.setPosition(p_position);
	}

	void SpriteComponent::SetSize(float x, float y)
	{
		m_sprite.setScale(x / m_textureSize.x, y / m_textureSize.y);
	}

	void SpriteComponent::SetScale(float x, float y)
	{
		m_sprite.setScale(x, y);
	}
}
