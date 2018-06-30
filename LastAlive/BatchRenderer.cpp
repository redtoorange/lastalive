#include "BatchRenderer.h"
#include "RawMesh.h"
#include "MeshInstance.h"
#include "Camera.h"

namespace Engine {

	void BatchRenderer::AddToBatch(MeshInstance* instance) {
		auto const mesh = instance->GetMesh();
		auto const position = m_opaqueInstances.find(mesh);

		if (position != m_opaqueInstances.end()) {
			m_opaqueInstances[mesh].push_back(instance);
		}
		else {
			m_opaqueInstances[mesh] = {instance};
		}
	}

	void BatchRenderer::EnableAplhaBlend(bool enable) {
		if (enable) {
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
		}
		else {
			glDisable(GL_DEPTH_TEST);
		}
	}

	void BatchRenderer::EnableFaceCulling(bool enable) {
		if (enable) {
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
		}
		else {
			glDisable(GL_CULL_FACE);
		}
	}

	void BatchRenderer::EnableDepthTesting(bool enable) {
		if(enable) {
			glDepthFunc(GL_LESS);
			glEnable(GL_DEPTH_TEST);
		}
		else {
			glDisable(GL_DEPTH_TEST);
		}
	}

	void BatchRenderer::ClearScreen() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void BatchRenderer::RenderBatch(Camera* currentCamera) {
		EnableDepthTesting(true);
		// EnableFaceCulling(true);
  
		// EnableAplhaBlend(true);
		// glEnable(GL_STENCIL_TEST);
		ClearScreen();

		for (auto& mesh : m_opaqueInstances) {
			// Prepare the mesh
			mesh.first->PrepareToDraw();

			for (MeshInstance* instance : mesh.second) {
				instance->Draw(currentCamera);
			}

			// Cleanup the mesh
			// mesh.first->CleanUpAfterDraw();
		}
		m_opaqueInstances.clear();

		// Render all with transparency
		// EnableAplhaBlend(true);
		// for (auto& mesh : m_transparentInstances) {
		// 	// Prepare the mesh
		// 	mesh.first->PrepareToDraw();
  //
		// 	for (MeshInstance* instance : mesh.second) {
		// 		instance->Draw(currentCamera);
		// 	}
  //
		// 	// Cleanup the mesh
		// 	mesh.first->CleanUpAfterDraw();
		// }
		// EnableAplhaBlend(false);
		// m_transparentInstances.clear();
	}
}
