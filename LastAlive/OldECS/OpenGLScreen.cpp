#include "OpenGLScreen.h"

namespace Engine {
	OpenGLScreen::OpenGLScreen() : sprite("assets/mario.png") {
		m_entities.push_back(&sprite);
		testCamera.MakeActive(true);
	}
}
