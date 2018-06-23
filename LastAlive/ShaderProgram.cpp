#include "ShaderProgram.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

namespace Engine {
	ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) {
		glewInit();
		GLuint vertexShader;
		LoadShader(vertexShader, vertexPath, GL_VERTEX_SHADER);

		GLuint fragmentShader;
		LoadShader(fragmentShader, fragmentPath, GL_FRAGMENT_SHADER);

		// shader Program
		m_program = glCreateProgram();
		glAttachShader(m_program, vertexShader);
		glAttachShader(m_program, fragmentShader);
		glLinkProgram(m_program);

		CheckCompileErrors(m_program, "PROGRAM");

		// delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void ShaderProgram::CheckCompileErrors(GLuint shader, const std::string& type) {
		GLint success;
		char infoLog[1024];

		if (type != "PROGRAM") {
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog <<
					"\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else {
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog <<
					"\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}

	ShaderProgram::~ShaderProgram() {
		SetBound(false);
		Delete();
	}

	bool ShaderProgram::LoadShader(GLuint& location, const std::string& path, GLenum type) {
		bool success = true;

		std::string shaderSource;
		std::ifstream shaderFile;

		// ensure ifstream objects can throw exceptions:
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			shaderFile.open(path);
			std::stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();
			shaderSource = shaderStream.str();
		}
		catch (std::ifstream::failure e) {
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}

		const char* shaderSourceC = shaderSource.c_str();

		location = glCreateShader(type);
		glShaderSource(location, 1, &shaderSourceC, NULL);
		glCompileShader(location);

		return success;
	}

	void ShaderProgram::SetBound(bool bound) {
		if(bound)
			glUseProgram(m_program);
		else
			glUseProgram(0);
	}

	void ShaderProgram::Delete() {
		glDeleteProgram(m_program);
	}

	void ShaderProgram::SetPerspective(const glm::mat4x4& perspective) {
		SetUniformMatrix("perspective", perspective);
	}

	void ShaderProgram::SetTransform(const glm::mat4x4& transform) {
		SetUniformMatrix("transform", transform);
	}

	void ShaderProgram::SetUniformMatrix(const std::string& name, const glm::mat4x4& value) {
		auto loc = glGetUniformLocation(m_program, name.c_str());
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
	}

	void ShaderProgram::SetUniformBool(const std::string& name, bool value) {
		auto loc = glGetUniformLocation(m_program, name.c_str());
		glUniform1i(loc, static_cast<GLint>(value));
	}

	void ShaderProgram::SetUniformFloat(const std::string& name, float value) {
		auto loc = glGetUniformLocation(m_program, name.c_str());
		glUniform1f(loc, value);
	}

	void ShaderProgram::SetUniformInt(const std::string& name, int value) {
		auto loc = glGetUniformLocation(m_program, name.c_str());
		glUniform1i(loc, value);
	}

	ShaderProgram ShaderProgram::GetDefaultShader() {
		return { "assets/vertex.glsl", "assets/fragment.glsl" };
	}
}
