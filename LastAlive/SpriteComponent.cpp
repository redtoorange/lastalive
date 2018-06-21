#include "SpriteComponent.h"
#include <iostream>

namespace LastAlive {
	SpriteComponent::SpriteComponent() {
		m_getsRender = true;
	}

	void SpriteComponent::Render(Engine::BatchRenderer& p_batch) {
		m_sprite.Render(p_batch);
	}

	void SpriteComponent::SetTexture(const sf::Texture& p_texture) {
		// m_sprite = sf::Sprite(p_texture);
		// m_textureSize = p_texture.getSize();
	}

	void SpriteComponent::SetPosition(const sf::Vector2f& p_position) {
		m_sprite.SetPosition(p_position.x, p_position.y);
	}

	void SpriteComponent::SetSize(float x, float y) {
		// m_sprite.SetScale(x / m_textureSize.x, y / m_textureSize.y);
	}

	void SpriteComponent::SetScale(float x, float y) {
		m_sprite.SetScale(x, y);
	}
}
