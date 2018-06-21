#include "PlayerInputComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "Vector2f.h"

namespace LastAlive
{
	PlayerInputComponent::PlayerInputComponent()
	{
		m_getsRender = false;
		m_getsUpdate = true;
		m_getsInput = true;
	}

	void PlayerInputComponent::HandleInput(sf::Event& p_event)
	{
		// Do nothing for now
	}

	void PlayerInputComponent::Update(float p_delta)
	{
		m_deltaInput = Engine::Vector2f{0, 0};

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			m_deltaInput.y += 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			m_deltaInput.y -= 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			m_deltaInput.x -= 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			m_deltaInput.x += 1;
	}

	bool PlayerInputComponent::InputRead() const
	{
		return (m_deltaInput.x != 0 || m_deltaInput.y != 0);
	}

	const Engine::Vector2f& PlayerInputComponent::GetDeltaInput() const
	{
		return m_deltaInput;
	}
}
