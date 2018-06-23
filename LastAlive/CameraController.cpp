#include "CameraController.h"
#include "Engine.h"
#include "RenderWindow.hpp"

namespace Engine {

	/////////////////////////////
	//	Camera2DController Impl
	/////////////////////////////
	void Camera2DController::Update(float deltaTime) {
		// glm::vec2 inputDelta{0, 0};
		//
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		// 	inputDelta.y += 1;
		// }
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		// 	inputDelta.y -= 1;
		// }
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		// 	inputDelta.x -= 1;
		// }
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		// 	inputDelta.x += 1;
		// }
		//
		// auto pos = GetPosition();
		// pos.x += inputDelta.x * deltaTime * m_speed;
		// pos.y += inputDelta.y * deltaTime * m_speed;
		// SetPosition(pos.x, pos.y);

		Camera2DNode::Update(deltaTime);
	}

	/////////////////////////////
	//	Camera3DController Impl
	/////////////////////////////

	Camera3DController::Camera3DController() {
		auto window = Engine::GetSingleton()->GetCurrentWindow();

		int x, y;
		SDL_GetWindowPosition(window->GetSDLWindow(), &x, &y);

		int w, h;
		SDL_GetWindowSize(window->GetSDLWindow(), &w, &h);

		m_mousePos = {x, y};
		m_mousePos.x += w / 2;
		m_mousePos.y += h / 2;
	}

	void Camera3DController::Update(float deltaTime) {
		auto camera = GetCamera();

		auto pos = GetPosition();
		const auto forward = camera->GetForward();
		const auto right = camera->GetRight();
		const auto up = camera->GetUp();

		auto state = SDL_GetKeyboardState(NULL);
		// Forward/Back
		if (state[SDL_SCANCODE_W]) {
			pos += forward * deltaTime * m_moveSpeed;
		}
		if (state[SDL_SCANCODE_S]) {
			pos -= forward * deltaTime * m_moveSpeed;
		}

		// Strafe
		if (state[SDL_SCANCODE_A]) {
			pos -= right * deltaTime * m_moveSpeed;
		}
		if (state[SDL_SCANCODE_D]) {
			pos += right * deltaTime * m_moveSpeed;
		}

		pos.y = 0;

		SetPosition(pos);

		int x, y;
		SDL_GetMouseState(&x, &y);

		int dx = x - m_mousePos.x;
		int dy = y - m_mousePos.y;
		// m_mousePos = {x, y};
		SDL_WarpMouseInWindow(SDL_GL_GetCurrentWindow(), m_mousePos.x, m_mousePos.y);

		// const auto newMousePos = sf::Mouse::getPosition();
		// const auto mouseDelta = newMousePos - m_mousePos;
		// sf::Mouse::setPosition(m_mousePos);

		auto rot = GetRotation();
		rot.x += -1 * dy * m_mouseSensitivity;
		rot.x = glm::clamp<float>(rot.x, -m_maxPitch, m_maxPitch);
		rot.z += dx * m_mouseSensitivity;
		SetRotation(rot);

		Camera3DNode::Update(deltaTime);
	}
}
