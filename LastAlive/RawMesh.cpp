#include "RawMesh.h"

namespace Engine {
	RawMesh::~RawMesh() {
		for (auto& vbo : m_vbos) {
			glDeleteBuffers(1, &vbo);
		}
		m_vbos.clear();

		glDeleteVertexArrays(1, &m_vao);
	}

	void RawMesh::PrepareToDraw() {
		// Enable all attributes
		glBindVertexArray(m_vao);

		// for (auto& attribute : m_attributes)
		// 	glEnableVertexAttribArray(attribute);
	}

	void RawMesh::Draw() {
		glDrawElements(GL_TRIANGLES, m_vertexCount, GL_UNSIGNED_INT, 0);
	}

	void RawMesh::CleanUpAfterDraw() {
		// Disable all attributes
		// for (auto& attribute : m_attributes)
		// 	glDisableVertexAttribArray(attribute);

		glBindVertexArray(0);
	}

	void RawMesh::LoadBufferData(GLenum target, std::vector<float>& data, GLuint position, GLuint size) {
		GLuint vbo;
		glGenBuffers(1, &vbo);

		// Create the data buffer
		glBindBuffer(target, vbo);
		glBufferData(target, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

		// Set the attribute pointer
		glVertexAttribPointer(position, size, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(position);

		// Register and cleanup
		glBindBuffer(target, 0);
		m_vbos.push_back(vbo);
		m_attributes.push_back(position);
	}

	void RawMesh::LoadElementBuffer(std::vector<GLuint>& data) {
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLuint), data.data(), GL_STATIC_DRAW);

		m_vbos.push_back(vbo);
	}

	void RawMesh::LoadModelData(std::vector<float>& positions, std::vector<float>& texCoords,
	                            std::vector<GLuint>& indices) {
		// Register a vao for the model
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		// Load the model's data to buffers
		LoadBufferData(GL_ARRAY_BUFFER, positions, 0, 3);
		LoadBufferData(GL_ARRAY_BUFFER, texCoords, 1, 2);
		LoadElementBuffer(indices);
		m_vertexCount = static_cast<GLuint>(indices.size());

		// Cleanup
		glBindVertexArray(0);
	}

	RectangleMesh::RectangleMesh() {
		LoadModelData(positions, textureCoords, indices);
	}
}
