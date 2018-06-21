#pragma once

#include <glm/mat4x4.hpp>

namespace Engine
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		glm::mat4x4 GetProjection() const;
		glm::mat4x4 GetView() const;


	protected:
		glm::vec3 m_position;

		float m_pitch = 0;
		float m_roll = 0;
		float m_yaw = 0;

		float m_nearClip = 0.1f;
		float m_farClip = 100.0f;
		float m_fieldOfView = 90.0f;
	};
}

