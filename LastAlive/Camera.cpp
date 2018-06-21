#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Engine.h"

namespace Engine {
	void Camera::MakeActive(bool active) {
		if (active)
			Engine::GetSingleton()->SetCurrentCamera(this);
		else
			Engine::GetSingleton()->SetCurrentCamera(nullptr);
	}

	bool Camera::IsActive() {
		return (Engine::GetSingleton()->GetCurrentCamera() == this);
	}

	void Camera::SetPosition(const glm::vec3& pos) {
		m_position = pos;
	}

	void Camera::SetRotation(const glm::vec3& rot) {
		m_pitch = rot.x;
		m_roll = rot.y;
		m_yaw = rot.z;
	}

	////////////////////////////////////////////////////////
	//	Perspective Camera
	////////////////////////////////////////////////////////
	glm::mat4x4 PerspectiveCamera::GetProjection() const {
		return glm::perspective<float>(m_fieldOfView, 800.0f / 600.0f, m_nearClip, m_farClip);
	}

	glm::mat4x4 PerspectiveCamera::GetView() const {
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void PerspectiveCamera::UpdateCamera() {
		// Calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y = sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_front = glm::normalize(front);

		// Also re-calculate the Right and Up vector
		m_right = glm::normalize(glm::cross(m_front, m_worldUp));
		// Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_up = glm::normalize(glm::cross(m_right, m_front));
	}

	////////////////////////////////////////////////////////
	//	Ortho Camera
	////////////////////////////////////////////////////////
	glm::mat4x4 OrthographicCamera::GetProjection() const {
		return glm::perspective<float>(m_fieldOfView, 800.0f / 600.0f, m_nearClip, m_farClip);
	}

	glm::mat4x4 OrthographicCamera::GetView() const {
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void OrthographicCamera::UpdateCamera() {
		// Calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y = sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_front = glm::normalize(front);

		// Also re-calculate the Right and Up vector
		m_right = glm::normalize(glm::cross(m_front, m_worldUp));
		// Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_up = glm::normalize(glm::cross(m_right, m_front));
	}
}
