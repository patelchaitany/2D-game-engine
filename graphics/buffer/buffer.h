#pragma once
#include<GL/glew.h>
namespace sparky {
	namespace graphics {
		class Buffer {

		private:
			GLuint m_BufferID;
			GLuint m_ComponetCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componetCount);

			void bind() const;
			void unbind() const;

			inline GLuint  getComponentCount() const { return m_ComponetCount; }


		};
	}
}