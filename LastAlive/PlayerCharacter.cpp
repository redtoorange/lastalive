#include "PlayerCharacter.h"

namespace LastAlive
{
	PlayerCharacter::PlayerCharacter(std::string texturePath)
		: m_positionComponent(10, 10)
	{
		Entity::AddComponent(&m_positionComponent);
		Entity::AddComponent(&m_inputComponent);
		Entity::AddComponent(&m_spriteComponent);

		m_texture.loadFromFile(texturePath);
		m_spriteComponent.SetTexture(m_texture);
		m_spriteComponent.SetPosition(m_positionComponent.GetPosition());
	}

	void PlayerCharacter::Update(float p_delta)
	{
		Entity::Update(p_delta);

		auto pos = m_positionComponent.GetPosition();
		pos += m_inputComponent.GetDeltaInput();
		m_positionComponent.SetPosition(pos);

		m_spriteComponent.SetPosition(m_positionComponent.GetPosition());
	}
}