#include "Engine.h"
#include "GameScreen.h"

int main()
{
	Engine::Engine e{800, 600};
	LastAlive::GameScreen gs;

	e.SetCurrentScreen(&gs);
	e.Start();

	return 0;
}
