#include "Renderer.h"

namespace Engine
{
	ModelRenderer::ModelRenderer()
		: m_defaultShader("assets/vertex.glsl", "assets/fragment.glsl")
	{
	}


	ShaderProgram* ModelRenderer::GetDefaultShader()
	{
		return &m_defaultShader;
	}

	ModelRenderer::~ModelRenderer()
	{
	}

	void ModelRenderer::Render(MeshInstance* instance)
	{
		m_instances.push_back(instance);
	}

	void ModelRenderer::Draw()
	{
		for (MeshInstance* mi : m_instances)
			mi->Draw();

		m_instances.clear();
	}
}
