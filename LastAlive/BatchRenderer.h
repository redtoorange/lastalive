#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

namespace Engine {
	class RawMesh;
	class MeshInstance;
	class Camera;

	using MeshBatch = std::unordered_map<RawMesh*, std::vector<MeshInstance*>>;

	class BatchRenderer {
	public:
		BatchRenderer() = default;

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
