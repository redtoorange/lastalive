#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include "Camera.h"

namespace Engine {
	class ShaderProgram;
	class RawMesh;
	class MeshInstance;

	using MeshBatch = std::unordered_map<RawMesh*, std::vector<MeshInstance*>>;

	class BatchRenderer {
	public:
		BatchRenderer();

		virtual ~BatchRenderer() = default;

		void AddToBatch(MeshInstance* instance);

		void RenderBatch(Camera* currentCamera);

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		MeshBatch m_instances;
	};
}
