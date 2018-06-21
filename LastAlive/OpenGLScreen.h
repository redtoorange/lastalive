#pragma once
#include "Screen.h"
#include "PlayerCharacter.h"

namespace Engine {
	class OpenGLScreen : public Screen {
	public:
		OpenGLScreen();

	private:
		LastAlive::PlayerCharacter sprite;
	};
}
