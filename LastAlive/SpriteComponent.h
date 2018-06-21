#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

namespace Engine {
	class Renderer;
}

namespace LastAlive {

	class SpriteComponent : public Engine::Component {
	public:
		SpriteComponent();

		// virtual void Render(sf::RenderWindow& p_window) override;

		void Render(Engine::BatchRenderer& p_batch) override;

		void SetTexture(const sf::Texture& p_texture);

		void SetPosition(const sf::Vector2f& p_position);

		void SetSize(float x, float y);

		void SetScale(float x, float y);

	private:
		Engine::Sprite m_sprite;
		sf::Vector2u m_textureSize;
	};
}
