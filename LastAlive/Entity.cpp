#include "Entity.h"
#include "Component.h"

namespace Engine {
	void Entity::Update(float p_delta) {
		for (auto& c : m_components)
			if (c->GetsUpdate())
				c->Update(p_delta);
	}

	void Entity::Render(sf::RenderWindow& p_window) {
		for (auto& c : m_components)
			if (c->GetsRender())
				c->Render(p_window);
	}

	void Entity::Render(BatchRenderer& p_batch) {
		for (auto& c : m_components)
			if (c->GetsRender())
				c->Render(p_batch);
	}

	void Entity::HandleInput(sf::Event& p_event) {
		for (auto& c : m_components)
			if (c->GetsInput())
				c->HandleInput(p_event);
	}

	void Entity::AddComponent(Component* component) {
		m_components.emplace_back(component);
	}
} //  namespace Engine
