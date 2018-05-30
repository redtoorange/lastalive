#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>

namespace LastAlive
{
	class PlayerInputComponent : public Engine::Component
	{
	public:
		PlayerInputComponent();

		virtual void HandleInput(sf::Event& p_event) override;

		virtual void Update(float p_delta) override;

		const sf::Vector2f& GetDeltaInput() const;

		bool InputRead() const;

	private:
		sf::Vector2f m_deltaInput;
	};
}
