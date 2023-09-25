#pragma once
#include"utils/utils.h"
#include"Maths/mat4.h"
#include"Maths/vec2.h"
#include"Maths/vec3.h"
#include"GL/glew.h"
namespace sparky {
	namespace graphics {
		class shaders {
		private:
			GLuint m_shaderID;
			const char* m_vertPath;
			const char* m_fragPath;
		public:
			shaders(const char* vertexPath, const char* fragPath);
			~shaders();


			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, float value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);
			void enable()const;
			void disable()const;

		private:
			GLint getUniformLocation(const GLchar *name);
			GLuint load();
		};
	}
}