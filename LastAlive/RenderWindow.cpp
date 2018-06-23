#include "RenderWindow.hpp"

namespace Engine {

	RenderWindow::RenderWindow(const std::string& title, int width, int height) {
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		                          SDL_WINDOW_OPENGL);
		if (window) {
			context = SDL_GL_CreateContext(window);
			if (context) {
				SDL_GL_MakeCurrent(window, context);
				SDL_GL_SetSwapInterval(-1);
				SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
				SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
			}
			else {
				SDL_Log("Failed to create the glContext.\n");
			}
		}
		else {
			SDL_Log("Failed to created the Render Window.\n");
		}

	}

	RenderWindow::~RenderWindow() {
		if (context)
			SDL_GL_DeleteContext(context);
		if (window)
			SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void RenderWindow::ShowWindow(bool show) {
		isShown = show;

		if (show)
			SDL_ShowWindow(window);
		else
			SDL_HideWindow(window);
	}

	void RenderWindow::SwapBuffers() {
		SDL_GL_SwapWindow(window);
	}
}
