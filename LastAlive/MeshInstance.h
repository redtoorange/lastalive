#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <glm/glm.hpp>

namespace Engine {
	class RawMesh;
	class ShaderProgram;

	class MeshInstance {
	public:
		MeshInstance() = default;

		MeshInstance(RawMesh* mesh);

		void SetShader(ShaderProgram* shader);

		void SetTexture(sf::Texture* texture);

		void SetPosition(const glm::vec3& position);

		void SetRotation(const glm::vec3& rotation);

		void SetScale(const glm::vec3& scale);

		void SetMesh(RawMesh* mesh);

		RawMesh* GetMesh() const;

		glm::vec3 GetRotation() const;

		glm::vec3 GetPosition() const;

		glm::mat4x4 GetTransform();

		void Draw();

	private:
		void CleanUp();

		void PerpareToDraw();

		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		ShaderProgram* m_pShader;
		RawMesh* m_pMesh;
		sf::Texture* m_texture;

		glm::vec3 m_position{0, 0, 0};
		glm::vec3 m_rotation{0, 0, 0};
		glm::vec3 m_scale{1, 1, 1};
	};
}
