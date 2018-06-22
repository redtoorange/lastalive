#include "CameraController.h"
#include <SFML/Window/Event.hpp>
#include "Engine.h"

namespace Engine {

	/////////////////////////////
	//	Camera2DController Impl
	/////////////////////////////
	void Camera2DController::Update(float deltaTime) {
		glm::vec2 inputDelta{0, 0};

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			inputDelta.y += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			inputDelta.y -= 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			inputDelta.x -= 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			inputDelta.x += 1;
		}

		auto pos = GetPosition();
		pos.x += inputDelta.x * deltaTime * m_speed;
		pos.y += inputDelta.y * deltaTime * m_speed;
		SetPosition(pos.x, pos.y);

		Camera2DNode::Update(deltaTime);
	}

	/////////////////////////////
	//	Camera3DController Impl
	/////////////////////////////

	Camera3DController::Camera3DController() {
		auto window = Engine::GetSingleton()->GetCurrentWindow();
		m_mousePos = window->getPosition();
		m_mousePos.x += window->getSize().x/2;
		m_mousePos.y += window->getSize().y/2;
	}

	void Camera3DController::Update(float deltaTime) {
		auto camera = GetCamera();

		auto pos = GetPosition();
		const auto forward = camera->GetForward();
		const auto right = camera->GetRight();
		const auto up = camera->GetUp();

		// Forward/Back
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			pos += forward * deltaTime * m_moveSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pos -= forward * deltaTime * m_moveSpeed;
		}

		// Strafe
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			pos -= right * deltaTime * m_moveSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pos += right * deltaTime * m_moveSpeed;
		}

		// Up/Down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			pos += up * deltaTime * m_moveSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			pos -= up * deltaTime * m_moveSpeed;
		}
		pos.y = 0;

		SetPosition(pos);
		

		const auto newMousePos = sf::Mouse::getPosition();
		const auto mouseDelta = newMousePos - m_mousePos;
		sf::Mouse::setPosition(m_mousePos);

		auto rot = GetRotation();
		rot.x += -1 * mouseDelta.y * m_mouseSensitivity;
		rot.x = glm::clamp<float>(rot.x, -m_maxPitch, m_maxPitch);
		rot.z += mouseDelta.x * m_mouseSensitivity;
		SetRotation(rot);

		Camera3DNode::Update(deltaTime);
	}
}
