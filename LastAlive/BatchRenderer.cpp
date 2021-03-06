#include "BatchRenderer.h"
#include "RawMesh.h"
#include "MeshInstance.h"
#include "Camera.h"

namespace Engine {

	void BatchRenderer::AddToBatch(MeshInstance* instance) {
		auto const mesh = instance->GetMesh();
		auto const position = m_instances.find(mesh);

		if (position != m_instances.end()) {
			m_instances[mesh].push_back(instance);
		}
		else {
			m_instances[mesh] = {instance};
		}
	}

	void BatchRenderer::RenderBatch(Camera* currentCamera) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);

		for (auto& mesh : m_instances) {
			// Prepare the mesh
			mesh.first->PrepareToDraw();

			for (MeshInstance* instance : mesh.second) {
				instance->Draw(currentCamera);
			}

			// Cleanup the mesh
			mesh.first->CleanUpAfterDraw();
		}

		m_instances.clear();
	}
}
