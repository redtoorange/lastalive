#pragma once
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
#include <string>

namespace Engine {
	class ShaderProgram {
	public:
		ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);

		virtual ~ShaderProgram();

		void Bind();

		void Unbind();

		void Delete();

		virtual void SetPerspective(const glm::mat4x4& perspective);

		virtual void SetTransform(const glm::mat4x4& transform);

		virtual void SetUniformMatrix(const std::string& name, const glm::mat4x4& value);

		virtual void SetUniformBool(const std::string& name, bool value);

		virtual void SetUniformFloat(const std::string& name, float value);

		virtual void SetUniformInt(const std::string& name, int value);

		static ShaderProgram GetDefaultShader();

	private:
		bool LoadShader(GLuint& location, const std::string& path, GLenum type);

		void CheckCompileErrors(GLuint shader, const std::string& type);

		GLuint m_program;
	};
}
