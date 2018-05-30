#include "Entity.h"
#include "Component.h"


namespace Engine
{
	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::Update(float p_delta)
	{
		for (auto& c : m_components)
			if (c->GetsUpdate())
				c->update(p_delta);
	}

	void Entity::Render(sf::RenderWindow& p_window)
	{
		for (auto& c : m_components)
			if (c->GetsRender())
				c->render(p_window);
	}

	void Entity::HandleInput(sf::Event& p_event)
	{
		for (auto& c : m_components)
			if (c->GetsInput())
				c->handleInput(p_event);
	}

	void Entity::AddComponent(Component* component)
	{
		m_components.emplace_back( component );
	}
} //  namespace Engine
