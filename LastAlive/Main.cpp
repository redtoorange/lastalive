#include "Engine.h"
#include "GameScreen.h"
#include "Entity.h"
#include "PositionComponent.h"
#include <iostream>

int main()
{
	Engine::Engine e{800, 600};
	LastAlive::GameScreen gs;

	Engine::Entity entity;
	entity.AddComponent( new LastAlive::PositionComponent(10, 10));
	auto comp = entity.GetComponent<LastAlive::PositionComponent>();

	if( comp )
	{
		std::cout << "Found Component!" << comp->GetPosition().x << "\t" << comp->GetPosition().y << "\n";
	}
	else
	{
		std::cout << "Failed to find component";
	}



	e.SetCurrentScreen(&gs);
	e.Start();

	return 0;
}
