#pragma once

#include <vector>
#include <gl/glew.h>


namespace Engine
{
	class Mesh
	{
	public:
		Mesh();
		virtual ~Mesh();

		void Draw();

	private:
		void LoadData();

		void LoadTextureBuffer();
		void LoadVertexBuffer();
		void LoadElementBuffer();

		GLuint m_vao;
		GLuint m_pos_vbo;
		GLuint m_ebo;
		GLuint m_texture_vbo;

		std::vector<float> verts =
		{
			0.5f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
		};

		std::vector<GLuint> indices = {
			0, 1, 3,
			1, 2, 3
		};

		std::vector<float> textureCoords =
		{
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f
		};
	};
}
