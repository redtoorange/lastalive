#include "MeshInstance.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Mesh.h"

namespace Engine
{
	MeshInstance::MeshInstance(Mesh* mesh)
		: m_pMesh(mesh)
	{
		sf::Image image;
		image.loadFromFile("assets/mario.png");
		image.flipVertically();

		m_texture.loadFromImage(image);
		m_texture.setRepeated(false);
		m_texture.setSmooth(true);
		m_texture.generateMipmap();
		

		m_position = glm::vec3{0, 0, 0};
		m_scale = glm::vec3{1, 1, 1};
		m_rotation = glm::vec3{0, 0, 0};
	}

	glm::mat4x4 MeshInstance::GetTransform()
	{
		glm::mat4x4 matrix;

		matrix = glm::translate(matrix, m_position);

		matrix = glm::rotate(matrix, m_rotation.x, {1, 0, 0});
		matrix = glm::rotate(matrix, m_rotation.y, {0, 1, 0});
		matrix = glm::rotate(matrix, m_rotation.z, {0, 0, 1});

		matrix = glm::scale(matrix, m_scale);

		return matrix;
	}

	void MeshInstance::SetPosition(const glm::vec3& position)
	{
		m_position = position;
	}

	void MeshInstance::SetRotation(const glm::vec3& rotation)
	{
		m_rotation = rotation;
	}

	void MeshInstance::SetScale(const glm::vec3& scale)
	{
		m_scale = scale;
	}


	void MeshInstance::SetShader(ShaderProgram* shader)
	{
		m_pShader = shader;
	}

	void MeshInstance::Draw()
	{
		sf::Texture::bind(&m_texture);

		m_pShader->Bind();
		m_pShader->SetTransform(GetTransform());
		m_pShader->SetPerspective(glm::mat4x4());

		m_pMesh->Draw();

		m_pShader->Unbind();
	}

	glm::vec3 MeshInstance::GetRotation() const
	{
		return m_rotation;
	}


	glm::vec3 MeshInstance::GetPosition() const
	{
		return m_position;
	}
}
