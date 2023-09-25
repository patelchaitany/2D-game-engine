#include "sahders.h"
#include <vector>
#include<iostream>

namespace sparky {
	namespace graphics {
		shaders::shaders(const char* vertexPath, const char* fragPath)
			: m_fragPath(fragPath),m_vertPath(vertexPath) {
			m_shaderID = load();
		}
		
		shaders::~shaders() {
			glDeleteProgram(m_shaderID);
		}

		GLuint shaders::load() {
			GLuint program = glCreateProgram();
			GLuint vretex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertex_S = FileRead::read_file(m_vertPath);
			std::string frag_S = FileRead::read_file(m_fragPath);

			const char* vertSource = vertex_S.c_str();
			const char* fragSource = frag_S.c_str();

			glShaderSource(vretex, 1,&vertSource, NULL);
			glCompileShader(vretex);

			GLint result;
			glGetShaderiv(vretex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(vretex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char>error(length);
				glGetShaderInfoLog(vretex, length, &length, &error[0]);
				std::cout <<"Failed to compile vertex shader"<< &error[0] << std::endl;
				glDeleteShader(vretex);
				return 0;
			}
			//fragment
			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			//GLint result;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char>error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader" << & error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vretex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vretex);
			glDeleteShader(fragment);

			return program;
		}

		GLint shaders::getUniformLocation(const GLchar *name) {
			return glGetUniformLocation(m_shaderID,name);
		}

		void shaders::setUniform1f(const GLchar* name, float value) {
			glUniform1f(getUniformLocation(name), value);
		}
		void shaders::setUniform1i(const GLchar* name, float value) {
			glUniform1i(getUniformLocation(name), value);
		}
		void shaders::setUniform2f(const GLchar* name, const maths::vec2& vector) {
			glUniform2f(getUniformLocation(name), vector.x,vector.y);
		}
		void shaders::setUniform3f(const GLchar* name, const maths::vec3& vector) {
			glUniform3f(getUniformLocation(name), vector.x,vector.y,vector.z);
		}
		void shaders::setUniform4f(const GLchar* name, const maths::vec4& vector) {
			glUniform4f(getUniformLocation(name), vector.x,vector.y,vector.z,vector.w);
		}
		void shaders::setUniformMat4(const GLchar* name, const maths::mat4& matrix) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);

		}

		void shaders::enable() const {
			glUseProgram(m_shaderID);
		}

		void shaders::disable() const {
			glUseProgram(0);
		}
	}
}
