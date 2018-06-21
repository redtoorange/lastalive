#include "MeshInstance.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "RawMesh.h"
#include "ShaderProgram.h"
#include "Camera.h"

namespace Engine {
	MeshInstance::MeshInstance(RawMesh* mesh)
		: m_pMesh(mesh) {

		m_position = glm::vec3{0, 0, 0};
		m_scale = glm::vec3{1, 1, 1};
		m_rotation = glm::vec3{0, 0, 0};
	}

	void MeshInstance::SetTexture(sf::Texture* texture) {
		m_texture = texture;
	}

	glm::mat4x4 MeshInstance::GetTransform() {
		glm::mat4x4 matrix{1.0};

		matrix = glm::translate(matrix, m_position);

		matrix = glm::rotate(matrix, m_rotation.x, {1, 0, 0});
		matrix = glm::rotate(matrix, m_rotation.y, {0, 1, 0});
		matrix = glm::rotate(matrix, m_rotation.z, {0, 0, 1});

		matrix = glm::scale(matrix, m_scale);

		return matrix;
	}

	void MeshInstance::SetPosition(const glm::vec3& position) {
		m_position = position;
	}

	void MeshInstance::SetRotation(const glm::vec3& rotation) {
		m_rotation = rotation;
	}

	void MeshInstance::SetScale(const glm::vec3& scale) {
		m_scale = scale;
	}

	void MeshInstance::SetShader(ShaderProgram* shader) {
		m_pShader = shader;
	}

	void MeshInstance::PerpareToDraw(Camera* currentCamera) {
		sf::Texture::bind(m_texture);
		m_pShader->Bind();

		m_pShader->SetUniformMatrix("modelTransform", GetTransform());
		if (currentCamera) {
			m_pShader->SetUniformMatrix("viewCamera", currentCamera->GetView());
			m_pShader->SetUniformMatrix("projectionCamera", currentCamera->GetProjection());
		}
		else {
			m_pShader->SetUniformMatrix("viewCamera", glm::mat4x4(1));
			m_pShader->SetUniformMatrix("projectionCamera", glm::mat4x4(1));
		}
	}

	void MeshInstance::CleanUp() {
		sf::Texture::bind(nullptr);
		m_pShader->Unbind();
	}

	void MeshInstance::Draw(Camera* currentCamera) {
		PerpareToDraw(currentCamera);
		m_pMesh->Draw();
		CleanUp();
	}

	glm::vec3 MeshInstance::GetRotation() const {
		return m_rotation;
	}

	glm::vec3 MeshInstance::GetPosition() const {
		return m_position;
	}

	RawMesh* MeshInstance::GetMesh() const {
		return m_pMesh;
	}

	void MeshInstance::SetMesh(RawMesh* mesh) {
		m_pMesh = mesh;
	}
}
