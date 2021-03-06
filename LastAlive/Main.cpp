#include "Engine.h"

#include <SDL.h>
#include <GL/glew.h>

// #include <SFML/OpenGL.hpp>
#include "Scene.h"
#include "Node.h"
#include "CameraController.h"
#include "RenderWindow.hpp"

std::unique_ptr<Engine::RenderWindow> renderWindow;

int main(int argc, char* argv[]) {
	 
	// sf::ContextSettings settings;
	// settings.depthBits = 24;
	// settings.stencilBits = 8;
	// settings.antialiasingLevel = 4;
	// settings.majorVersion = 3;
	// settings.minorVersion = 3;
 //
	// sf::RenderWindow window(sf::VideoMode{1422, 800}, "Last Alive", sf::Style::Default, settings);
	// window.setActive(true);
	// window.setMouseCursorGrabbed(true);
	// window.setMouseCursorVisible(false);
	// window.setFramerateLimit(60);
	renderWindow = std::make_unique<Engine::RenderWindow>("Last Alive");
	glewInit();

	Engine::Engine e{ renderWindow.get()};
	Engine::Scene scene;

	Engine::SpriteNode spriteNode;
	spriteNode.AddNode(new Engine::Camera3DController());
	auto cam = spriteNode.GetNode<Engine::Camera3DController>();
	cam->SetActive(true);

	auto cube = new Engine::CubeModelNode();
	cube->SetPosition({-2, 0, -2});
	spriteNode.AddNode(cube);

	scene.SetRootNode(&spriteNode);

	e.SetCurrentScene(&scene);
	e.Start();

	return 0;
}
