#include "Engine.h"
#include "GameScreen.h"

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include "OpenGLScreen.h"
#include "Scene.h"
#include "Node.h"

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	sf::RenderWindow window(sf::VideoMode{1422, 800}, "Last Alive", sf::Style::Default, settings);
	window.setActive(true);
	glewInit();

	Engine::Engine e{&window};
	Engine::Scene scene;

	Engine::SpriteNode spriteNode;
	spriteNode.AddNode(new Engine::Camera2DNode());
	auto cam = spriteNode.GetNode<Engine::Camera2DNode>();
	cam->SetActive(true);
	
	
	scene.SetRootNode(&spriteNode);



	e.SetCurrentScene(&scene);
	e.Start();

	return 0;
}
