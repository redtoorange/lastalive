#pragma once

#include "MeshInstance.h"
#include "RawMesh.h"
#include "ShaderProgram.h"
#include "Texture.hpp"

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
		Texture m_texture;
		ShaderProgram m_shader;
		MeshInstance m_meshInstance;
		RectangleMesh m_spriteMesh;
	};
}
