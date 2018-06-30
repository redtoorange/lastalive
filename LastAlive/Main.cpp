#include "Engine.h"
#include <SDL.h>
#include "Scene.h"
#include "Node.h"
#include "CameraController.h"
#include "RenderWindow.hpp"

int main(int argc, char* argv[]) {
	Engine::RenderWindow renderWindow{"Last Alive"};
	

	Engine::Engine e{&renderWindow};

	Engine::Scene scene;
	Engine::SpriteNode spriteNode;
	
	auto cam = new Engine::Camera3DController();
	cam->SetActive(true);
	spriteNode.AddNode(cam);

	auto count = 5;
	auto dist = 5;
	for (int x = 0; x < count; x++) {
		for (int y = 0; y < count; y++) {
			for (int z = 0; z < count; z++) {
				auto cube = new Engine::CubeModelNode();
				cube->SetPosition({-x * dist, y * dist, -z * dist});
				spriteNode.AddNode(cube);
			}
		}
	}

	scene.SetRootNode(&spriteNode);

	e.SetCurrentScene(&scene);
	e.Start();

	return 0;
}
