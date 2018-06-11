#pragma once

#include "ShaderProgram.h"
#include <SFML/Graphics/Texture.hpp>
#include <glm/glm.hpp>

namespace Engine
{
	class Mesh;

	class MeshInstance
	{
	public:
		MeshInstance(Mesh* mesh);

		void SetPosition(const glm::vec3& position);
		void SetRotation(const glm::vec3& rotation);
		void SetScale(const glm::vec3& scale);

		glm::vec3 GetRotation() const;
		glm::vec3 GetPosition() const;
		glm::mat4x4 GetTransform();

		void SetShader(ShaderProgram* shader);
		void Draw();

	private:
		ShaderProgram* m_pShader;
		Mesh* m_pMesh;
		sf::Texture m_texture;

		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}
