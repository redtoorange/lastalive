#pragma once
#include "Component.h"
#include "Vector2f.h"

namespace LastAlive
{
	class PlayerInputComponent : public Engine::Component
	{
	public:
		PlayerInputComponent();

		virtual void HandleInput(sf::Event& p_event) override;

		virtual void Update(float p_delta) override;

		const Engine::Vector2f& GetDeltaInput() const;

		bool InputRead() const;

	private:
		Engine::Vector2f m_deltaInput;
	};
}
