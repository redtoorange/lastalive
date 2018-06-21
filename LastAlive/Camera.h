#pragma once

#include <glm/mat4x4.hpp>

namespace Engine {
	class Camera {
	public:
		Camera() = default;

		virtual ~Camera() = default;

		virtual glm::mat4x4 GetProjection() const = 0;

		virtual glm::mat4x4 GetView() const = 0;

		virtual void UpdateCamera() = 0;

		void MakeActive(bool active);

		bool IsActive();

		void SetPosition(const glm::vec3& pos);

		void SetRotation(const glm::vec3& rot);

	protected:
		glm::vec3 m_position{0, 0, 1.0f};

		float m_pitch = 0;
		float m_roll = 0;
		float m_yaw = -90.0f;

		float m_nearClip = 0.1f;
		float m_farClip = 100.0f;
		float m_fieldOfView = 90.0f;

		glm::vec3 m_front{0.0f, 0.0f, -1.0f};
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp{0.0f, 1.0f, 0.0f};
	};

	class PerspectiveCamera : public Camera {

	public:
		glm::mat4x4 GetProjection() const override;

		glm::mat4x4 GetView() const override;

		void UpdateCamera() override;
	};

	class OrthographicCamera : public Camera {

	public:
		glm::mat4x4 GetProjection() const override;

		glm::mat4x4 GetView() const override;

		void UpdateCamera() override;
	};
}
