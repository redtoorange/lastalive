#pragma once
#include <SDL.h>
#include <string>

namespace Engine {
	class RenderWindow {
	public:
		RenderWindow(const std::string& title = "OpenGL Window", int width = 1600, int height = 900);

		virtual ~RenderWindow();

		void ShowWindow(bool show);

		void SwapBuffers();

		SDL_Window* GetSDLWindow() { return window; };

	private:
		SDL_Window* window = nullptr;
		SDL_GLContext context = nullptr;
		bool initialized = false;
		bool isShown = false;
	};
}
