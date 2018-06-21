#include "Node.h"

namespace Engine {
	/////////////////////////////
	//	Node Node Impl
	/////////////////////////////
	void Node::Update(float deltaTime) {
		for (auto& node : m_children) {
			if (node)
				node->Update(deltaTime);
		}
	}

	void Node::Render(BatchRenderer& batch) {
		for (auto& node : m_children) {
			if (node)
				node->Render(batch);
		}
	}

	void Node::Input() {
		for (auto& node : m_children) {
			if (node)
				node->Input();
		}
	}

	void Node::AddNode(Node* newNode) {
		m_children.emplace_back(newNode);
	}

	void Node::RemoveNode(Node* deadNode) {
		for (auto iter = m_children.begin(); iter != m_children.end(); ++iter) {
			if((*iter).get() == deadNode) {
				m_children.erase(iter);
				break;
			}
		}
	}

	/////////////////////////////
	//	Node2D Node Impl
	/////////////////////////////
	void Node2D::SetPosition(float x, float y) {
		m_position.x = x;
		m_position.y = y;
	}

	void Node2D::SetScale(float width, float height) {
		m_scale.x = width;
		m_scale.y = height;
	}

	void Node2D::SetRotation(float rotation) {
		m_rotation = rotation;
	}

	glm::vec2 Node2D::GetPosition() const { return m_position; }

	glm::vec2 Node2D::GetScale() const { return m_scale; }

	float Node2D::GetRotation() const { return m_rotation; }

	/////////////////////////////
	//	Sprite Node Impl
	/////////////////////////////
	void SpriteNode::Update(float deltaTime) {
		const auto pos = GetPosition();
		m_sprite.SetPosition(pos.x, pos.y);

		const auto scale = GetScale();
		m_sprite.SetScale(scale.x, scale.y);

		Node2D::Update(deltaTime);
	}

	void SpriteNode::Render(BatchRenderer& batch) {
		m_sprite.Render(batch);

		Node2D::Render(batch);
	}

	/////////////////////////////
	//	Sprite Node Impl
	/////////////////////////////

	void Camera2DNode::SetActive(bool active) {
		m_camera.MakeActive(active);
	}

	void Camera2DNode::Update(float deltaTime) {
		auto pos = GetPosition();
		m_camera.SetPosition({pos.x, pos.y, 1.0f});
		
		m_camera.UpdateCamera();
	}
}
