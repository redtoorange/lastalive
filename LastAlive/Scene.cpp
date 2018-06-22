#include "Scene.h"
#include "Node.h"
#include "BatchRenderer.h"
#include <SFML/Window/Event.hpp>

namespace Engine {
	void Scene::Update(float deltaTime) {
		if (m_rootNode)
			m_rootNode->Update(deltaTime);
	}

	void Scene::Render(BatchRenderer& batch) {
		if (m_rootNode)
			m_rootNode->Render(batch);
	}

	void Scene::Input(sf::Event& event) {
		if (m_rootNode)
			m_rootNode->Input(event);
	}

	void Scene::SetRootNode(Node* newRoot) {
		m_rootNode = newRoot;
	}

	Node* Scene::GetRootNode() {
		return m_rootNode;
	}
}
