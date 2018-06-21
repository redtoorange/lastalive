#include "Screen.h"

#include "BatchRenderer.h"
#include "Entity.h"

namespace Engine {
	void Screen::Update(float p_delta) {
		for (auto& e : m_entities)
			e->Update(p_delta);
	}

	void Screen::Render(sf::RenderWindow& p_window) {
		for (auto& e : m_entities)
			e->Render(p_window);
	}

	void Screen::Render(BatchRenderer& p_batch) {
		for (auto& e : m_entities)
			e->Render(p_batch);
	}

	void Screen::HandleInput(sf::Event& p_event) {
		for (auto& e : m_entities)
			e->HandleInput(p_event);
	}
} //  namespace Engine
