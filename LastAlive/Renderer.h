#pragma once
#include "ShaderProgram.h"
#include "Mesh.h"
#include "MeshInstance.h"

namespace Engine
{
	class ModelRenderer
	{
	public:
		ModelRenderer();
		~ModelRenderer();

//		void QueueModel( MeshInstance* instance);
		void Render( MeshInstance* instance );
		void Draw();
		ShaderProgram* GetDefaultShader();
//		MeshInstance* GetMesh();

	private:
		ShaderProgram m_defaultShader;

//		Mesh squareMesh;
//		MeshInstance* meshInstance;

		std::vector<MeshInstance*> m_instances;
		std::vector<Mesh*> m_meshes;
	};
}
