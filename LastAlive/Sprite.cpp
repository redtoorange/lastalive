#include "Sprite.hpp"
#include "BatchRenderer.h"
#include "RawMesh.h"
#include <iostream>
#include "ShaderProgram.h"

namespace Engine {
	Sprite::Sprite() : m_shader(ShaderProgram::GetDefaultShader()) {
		m_meshInstance.SetMesh(&m_spriteMesh);
		m_meshInstance.SetShader(&m_shader);

		m_texture.LoadFromFile("assets/mario.png");
		m_texture.SetSmooth(true);

		m_meshInstance.SetTexture(&m_texture);
	}

	void Sprite::Render(BatchRenderer& p_batch) {
		p_batch.AddToBatch(&m_meshInstance);
	}

	Sprite::~Sprite() {}

	void Sprite::SetPosition(float x, float y) {
		m_meshInstance.SetPosition({x, y, 0});
	}

	void Sprite::SetScale(float x, float y) {
		m_meshInstance.SetScale({x, y, 1});
	}
}
