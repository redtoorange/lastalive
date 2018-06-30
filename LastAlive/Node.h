#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "Sprite.hpp"
#include "Camera.h"

namespace sf {
	class Event;
}

namespace Engine {
	class Node {
	public:
		Node() = default;

		virtual ~Node() = default;

		/// Call Update on all children
		virtual void Update(float deltaTime);

		/// Call AddToBatch on all children
		virtual void Render(BatchRenderer& batch);

		/// Call Input on all children
		virtual void Input(sf::Event& event);

		/// Add a node and assume ownership
		void AddNode(Node* newNode);

		/// Remove a node and delete it
		void RemoveNode(Node* deadNode);

		/// Find a node and get a pointer it
		template <class T>
		T* GetNode() {
			for (auto& node : m_children) {
				T* n = dynamic_cast<T*>(node.get());
				if (n) {
					return n;
				}
			}
			return nullptr;
		}

	private:
		std::vector<std::unique_ptr<Node>> m_children;
	};

	class Spatial : public Node {
	public:
		Spatial() = default;

		virtual ~Spatial() = default;

		void SetPosition(const glm::vec3& position);

		void SetScale(const glm::vec3& scale);

		void SetRotation(const glm::vec3& rotation);

		glm::vec3 GetPosition() const;

		glm::vec3 GetScale() const;

		glm::vec3 GetRotation() const;

	private:
		glm::vec3 m_position{0.0f, 0.0f, 0.0f};
		glm::vec3 m_scale{1.0f, 1.0f, 1.0f};
		glm::vec3 m_rotation{0.0f, 0.0f, 0.0f};
	};

	class CubeModelNode : public Spatial {
	public:
		CubeModelNode();

		void Update(float deltaTime) override;

		void Render(BatchRenderer& batch) override;

	private:
		MeshInstance instance;
		CubeMesh mesh;

		ShaderProgram shader;
		Texture texture;
	};

	class Camera3DNode : public Spatial {
	public:
		Camera3DNode();

		virtual ~Camera3DNode() = default;

		void SetActive(bool active);

		void Update(float deltaTime) override;

	protected:
		PerspectiveCamera* GetCamera();

	private:
		PerspectiveCamera m_camera;
	};

	class Node2D : public Node {
	public:
		Node2D() = default;

		virtual ~Node2D() = default;

		void SetPosition(float x, float y);

		void SetScale(float width, float height);

		void SetRotation(float rotation);

		glm::vec2 GetPosition() const;

		glm::vec2 GetScale() const;

		float GetRotation() const;

	private:
		glm::vec2 m_position{0.0f, 0.0f};
		glm::vec2 m_scale{1.0f, 1.0f};
		float m_rotation{0.0f};
	};

	class SpriteNode : public Node2D {
	public:

		void Update(float deltaTime) override;

		void Render(BatchRenderer& batch) override;

	private:
		Sprite m_sprite;
	};

	class Camera2DNode : public Node2D {
	public:
		void SetActive(bool active);

		void Update(float deltaTime) override;

	private:
		OrthographicCamera m_camera;
	};
}
