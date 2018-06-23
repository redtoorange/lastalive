#pragma once
#include "Node.h"

namespace Engine {
	class Camera2DController : public Camera2DNode {
	public:
		Camera2DController() = default;

		virtual ~Camera2DController() = default;

		void Update(float deltaTime) override;

	private:
		float m_speed = 10.0f;
	};

	class Camera3DController : public Camera3DNode {
	public:
		Camera3DController();

		virtual ~Camera3DController() = default;

		void Update(float deltaTime) override;

	private:
		float m_moveSpeed = 2.5;
		float m_mouseSensitivity = 0.1f;
		float m_maxPitch = 75.0f;
		glm::vec2 m_mousePos;
	};
}
