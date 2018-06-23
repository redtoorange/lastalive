#pragma once

#include <vector>
#include <GL/glew.h>

namespace Engine {
	/**
	 * \brief RawMesh contains the GL code needed to load and unload
	 * a mesh to the GPU.
	 */
	class RawMesh {
	public:
		RawMesh() = default;

		virtual ~RawMesh();

		// A RawMesh manages data on the GPU, it should not be copied, instead load the model in again
		RawMesh(const RawMesh& other) = delete;

		RawMesh& operator=(const RawMesh& other) = delete;

		///	Prepare the model's data for drawing
		virtual void PrepareToDraw();

		/// AddToBatch the model.
		virtual void Draw();

		///	Cleanup the model's data after it has been drawn
		virtual void CleanUpAfterDraw();

	protected:
		/**
		 * \brief Load a model's data to the GPU and store it in a vao.
		 * \param positions data set that contains the vertex positions as sets of 3 floats
		 * \param texCoords data set that contains the texture coords as sets of 2 floats
		 * \param indices data set that contains the index positions as integers
		 */
		void LoadModelData(std::vector<float>& positions, std::vector<float>& texCoords, std::vector<GLuint>& indices);

		void LoadModelData(std::vector<float>& positions, std::vector<float>& texCoords);

	private:
		/**
		 *	\brief	Load the model's indices into the index buffer.
		 *	\param data set of indices as GLuints
		 */
		void LoadElementBuffer(std::vector<GLuint>& data);

		/**
		 *	\brief	Load a set of data into a specific vbo
		 *	\param target	Type of buffer (GL_ARRAY_BUFFER)
		 *	\param data Set of data to upload
		 *	\param position attribute index
		 *	\param size size of data (3 for vertices, x, y, z)
		 */
		void LoadBufferData(GLenum target, std::vector<float>& data, GLuint position, GLuint size);

		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		GLuint m_vao;
		GLuint m_vertexCount;
		std::vector<GLuint> m_vbos;
		std::vector<GLuint> m_attributes;
	};

	/**
	 * \brief Rectangle mesh is a simple 2D plane that can have a texture mapped
	 * to it.
	 */
	class RectangleMesh : public RawMesh {
	public:
		RectangleMesh();

		~RectangleMesh() = default;

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		std::vector<float> positions =
		{
			0.5f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
		};

		std::vector<float> textureCoords =
		{
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f
		};

		std::vector<GLuint> indices = {
			0, 1, 3,
			1, 2, 3
		};
	};

	/**
	* \brief Cube mesh is a simple 2D plane that can have a texture mapped
	* to it.
	*/
	class CubeMesh : public RawMesh {
	public:
		CubeMesh();

		~CubeMesh() = default;

		void Draw() override;

	private:
		////////////////////////////////////////////////
		//	Member Data
		////////////////////////////////////////////////
		std::vector<float> positions =
		{
			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, 0.5f, -0.5f,
			0.5f, 0.5f, -0.5f,
			-0.5f, 0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f, -0.5f, 0.5f,
			0.5f, -0.5f, 0.5f,
			0.5f, 0.5f, 0.5f,
			0.5f, 0.5f, 0.5f,
			-0.5f, 0.5f, 0.5f,
			-0.5f, -0.5f, 0.5f,

			-0.5f, 0.5f, 0.5f,
			-0.5f, 0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, 0.5f,
			-0.5f, 0.5f, 0.5f,

			0.5f, 0.5f, 0.5f,
			0.5f, 0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, 0.5f,
			0.5f, 0.5f, 0.5f,

			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, 0.5f,
			0.5f, -0.5f, 0.5f,
			-0.5f, -0.5f, 0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f, 0.5f, -0.5f,
			0.5f, 0.5f, -0.5f,
			0.5f, 0.5f, 0.5f,
			0.5f, 0.5f, 0.5f,
			-0.5f, 0.5f, 0.5f,
			-0.5f, 0.5f, -0.5f
		};

		std::vector<float> textureCoords =
		{
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,

			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,

			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,
			1.0f, 0.0f,

			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,
			1.0f, 0.0f,

			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f,

			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f
		};
	};
}
