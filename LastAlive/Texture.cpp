#include "Texture.hpp"
#include <SDL.h>
#include <SDL_image.h>

namespace Engine {
	Texture::Texture(const std::string& path) {
		LoadFromFile(path);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &textureID);
	}

	void Texture::SetBound(bool bound) {
		if(bound)
			glBindTexture(GL_TEXTURE_2D, textureID);
		else
			glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::SetRepeats(bool repeats) {
		SetBound(true);

		if(repeats) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		if (repeats) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NONE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NONE);
		}
		
		SetBound(false);
	}

	void Texture::SetSmooth(bool smooth) {
		SetBound(true);

		if(smooth) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		else {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NONE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NONE);
		}
		
		SetBound(false);
	}

	void Texture::GenerateMipMap() {
		SetBound(true);
		glGenerateMipmap(GL_TEXTURE_2D);
		SetBound(false);
	}

	void Texture::LoadFromFile(const std::string& path) {
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface) {

			glGenTextures(1, &textureID);
			SetBound(true);
			const auto h = loadedSurface->h;
			const auto w = loadedSurface->w;
			const auto data = loadedSurface->pixels;
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			SetBound(false);

			SDL_FreeSurface(loadedSurface);
		}
		else {
			SDL_Log("Failed to load image %s", path.c_str());
		}
	}
}
