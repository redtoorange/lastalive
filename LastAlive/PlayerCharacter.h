#pragma once
#include "Entity.h"
#include "PlayerInputComponent.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include <SFML/Graphics.hpp>

namespace LastAlive
{
	class PlayerCharacter : public Engine::Entity
	{
	public:
		PlayerCharacter(std::string texturePath);

		virtual void Update(float p_delta) override;

	private:
		PlayerInputComponent m_inputComponent;
		SpriteComponent m_spriteComponent;
		PositionComponent m_positionComponent;

		// sf::Texture m_texture;

		float speed = 1.0f;
	};
}
