#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>


namespace Engine
{
	Camera::Camera() : m_position(0, 0, 0)
	{
	}


	Camera::~Camera()
	{
	}


	glm::mat4x4 Camera::GetProjection() const
	{
		glm::mat4x4 view = glm::perspective<float>(m_fieldOfView, 800.0f / 600.0f, m_nearClip, m_farClip);

		return view;
	}

	glm::mat4x4 Camera::GetView() const
	{
		glm::mat4x4 view{};

		return view;
	}
}
