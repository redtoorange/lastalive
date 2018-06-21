#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

namespace Engine {
	class ShaderProgram;
	class RawMesh;
	class MeshInstance;

	using MeshBatch = std::unordered_map<RawMesh*, std::vector<MeshInstance*>>;

	class BatchRenderer {
	public:
		BatchRenderer();

		virtual ~BatchRenderer() = default;

		void Render(MeshInstance* instance);

		void RenderBatch();

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		MeshBatch m_instances;
	};
}
