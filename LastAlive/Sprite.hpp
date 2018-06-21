#pragma once
#include <SFML/Graphics/Texture.hpp>
#include "MeshInstance.h"
#include "RawMesh.h"
#include "ShaderProgram.h"

namespace Engine {
	class BatchRenderer;

	class Sprite {
	public:
		Sprite();

		virtual ~Sprite();

		void Render(BatchRenderer& p_batch);

		void SetPosition(float x, float y);

		void SetScale(float x, float y);

	private:
		sf::Texture m_texture;

		ShaderProgram m_shader;
		MeshInstance m_meshInstance;
		RectangleMesh m_spriteMesh;
	};
}
