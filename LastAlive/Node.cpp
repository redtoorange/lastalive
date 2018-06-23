#include "Node.h"
#include "BatchRenderer.h"
#include "Engine.h"

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

	void Node::Input(sf::Event& event) {
		for (auto& node : m_children) {
			if (node)
				node->Input(event);
		}
	}

	void Node::AddNode(Node* newNode) {
		m_children.emplace_back(newNode);
	}

	void Node::RemoveNode(Node* deadNode) {
		for (auto iter = m_children.begin(); iter != m_children.end(); ++iter) {
			if ((*iter).get() == deadNode) {
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
	//	Camera2DNode Impl
	/////////////////////////////
	void Camera2DNode::SetActive(bool active) {
		m_camera.MakeActive(active);
	}

	void Camera2DNode::Update(float deltaTime) {
		auto pos = GetPosition();
		m_camera.SetPosition({pos.x, pos.y, 1.0f});

		m_camera.UpdateCamera();

		Node2D::Update(deltaTime);
	}

	/////////////////////////////
	//	Spatial Node Impl
	/////////////////////////////
	void Spatial::SetPosition(const glm::vec3& position) {
		m_position = position;
	}

	void Spatial::SetScale(const glm::vec3& scale) {
		m_scale = scale;
	}

	void Spatial::SetRotation(const glm::vec3& rotation) {
		m_rotation = rotation;
	}

	glm::vec3 Spatial::GetPosition() const {
		return m_position;
	}

	glm::vec3 Spatial::GetScale() const {
		return m_scale;
	}

	glm::vec3 Spatial::GetRotation() const {
		return m_rotation;
	}

	/////////////////////////////
	//	Camera3D Node Impl
	/////////////////////////////
	Camera3DNode::Camera3DNode() {
		SetRotation(m_camera.GetRotation());
		SetPosition(m_camera.GetPosition());
	}

	void Camera3DNode::SetActive(bool active) {
		m_camera.MakeActive(active);
	}

	void Camera3DNode::Update(float deltaTime) {
		m_camera.SetPosition(GetPosition());
		m_camera.SetRotation(GetRotation());

		m_camera.UpdateCamera();

		Spatial::Update(deltaTime);
	}

	PerspectiveCamera* Camera3DNode::GetCamera() {
		return &m_camera;
	}

	/////////////////////////////
	//	CubeModelNode Impl
	/////////////////////////////
	CubeModelNode::CubeModelNode() : shader(ShaderProgram::GetDefaultShader()){
		instance.SetMesh(&mesh);

		instance.SetPosition(GetPosition());
		instance.SetRotation(GetRotation());
		instance.SetScale(GetScale());

		texture.LoadFromFile("assets/debug.png");
		texture.SetRepeats(false);
		texture.SetSmooth(true);
		texture.GenerateMipMap();

		instance.SetTexture(&texture);
		instance.SetShader(&shader);
	}

	void CubeModelNode::Update(float deltaTime) {
		instance.SetPosition(GetPosition());
		instance.SetRotation(GetRotation());
		instance.SetScale(GetScale());

		Spatial::Update(deltaTime);
	}

	void CubeModelNode::Render(BatchRenderer& batch) {
		batch.AddToBatch(&instance);
		Spatial::Render(batch);
	}
}
