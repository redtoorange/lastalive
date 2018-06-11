#include "Engine.h"
#include "GameScreen.h"
#include <SFML/OpenGL.hpp>
#include <GL/glew.h>


int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	sf::RenderWindow window(sf::VideoMode{800, 600}, "Last Alive", sf::Style::Default, settings);
	window.setActive(true);
	glewInit();

	Engine::Engine e{&window};
	LastAlive::GameScreen gs;

	e.SetCurrentScreen(&gs);
	e.Start();

	return 0;
}
