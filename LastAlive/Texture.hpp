#pragma once

#include <GL/glew.h>
#include <string>

namespace Engine {
	class Texture {
	public:
		Texture() = default;

		Texture(const std::string& path);

		virtual ~Texture();

		void SetRepeats(bool repeats);

		void SetSmooth(bool smooth);

		void GenerateMipMap();

		void LoadFromFile(const std::string& path);

		void SetBound(bool bound);

		bool HasTransparency() { transparent; };

	private:
		GLuint textureID;
		bool transparent = false;
	};
}
