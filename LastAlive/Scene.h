#pragma once

namespace sf {
	class Event;
}

namespace Engine {
	class Node;
	class BatchRenderer;

	class Scene {
	public:
		Scene() = default;

		virtual ~Scene() = default;

		virtual void Update(float deltaTime);

		virtual void Render(BatchRenderer& batch);

		virtual void Input(sf::Event& event);

		virtual void SetRootNode(Node* newRoot);

		virtual Node* GetRootNode();

	private:
		Node* m_rootNode = nullptr;
	};
}
