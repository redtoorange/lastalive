#pragma once

namespace Engine {
	class Node;
	class BatchRenderer;

	class Scene {
	public:
		Scene() = default;

		virtual ~Scene() = default;

		virtual void Update(float deltaTime);

		virtual void Render(BatchRenderer& batch);

		virtual void Input();

		virtual void SetRootNode(Node* newNode);

		virtual Node* GetRootNode();

	private:
		Node* m_rootNode;
	};
}
