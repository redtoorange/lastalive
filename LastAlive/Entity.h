#pragma once
#include <vector>
#include <memory>
#include "BatchRenderer.h"

namespace sf {
	class RenderWindow;
	class Event;
}

namespace Engine {
	class Component;

	class Entity {
	public:
		Entity() = default;

		virtual ~Entity() = default;

		/// Update calls the Update function on all updatable components of this entity
		virtual void Update(float p_delta);

		/// Render calls the Render function on all renderable components of this entity
		virtual void Render(sf::RenderWindow& p_window);

		virtual void Render(BatchRenderer& p_batch);

		/// Handle input calls the HandleInput function on all components of this entity 
		virtual void HandleInput(sf::Event& p_event);

		/// Add a component to this entity, this entity will clean it up when destroyed
		virtual void AddComponent(Component* component);

		/// Seach the component bag of this entity and return the first instance of a component
		template <class T>
		T* GetComponent();

	protected:
		std::vector<Component*> m_components;
	};

	template <class T>
	T* Entity::GetComponent() {
		// Search all components
		for (auto& c : m_components) {
			// Try to cast it
			T* comp = dynamic_cast<T*>(c);

			// If it can be cast, its a match, return it
			if (comp)
				return comp;
		}

		// No matches
		return nullptr;
	}
} // namespace Engine
