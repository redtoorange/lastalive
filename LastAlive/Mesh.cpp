#include "Mesh.h"

namespace Engine
{
	Mesh::Mesh()
	{
		LoadData();
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_pos_vbo);
		glDeleteBuffers(1, &m_ebo);
		glDeleteBuffers(1, &m_texture_vbo);
		glDeleteVertexArrays(1, &m_vao);
	}

	void Mesh::Draw()
	{
		glBindVertexArray(m_vao);
		glEnableVertexAttribArray(0);

		glDrawElements(GL_TRIANGLES, verts.size(), GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

	void Mesh::LoadTextureBuffer()
	{
		// Texture Buffer
		glGenBuffers(1, &m_texture_vbo);

		glBindBuffer(GL_ARRAY_BUFFER, m_texture_vbo);
		glBufferData(GL_ARRAY_BUFFER, textureCoords.size() * sizeof(float), textureCoords.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Mesh::LoadVertexBuffer()
	{
		// Vert Buffer
		glGenBuffers(1, &m_pos_vbo);

		glBindBuffer(GL_ARRAY_BUFFER, m_pos_vbo);
		glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), verts.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Mesh::LoadElementBuffer()
	{
		// Elements
		glGenBuffers(1, &m_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	}

	void Mesh::LoadData()
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		LoadVertexBuffer();
		LoadElementBuffer();
		LoadTextureBuffer();

		glBindVertexArray(0);
	}
}
