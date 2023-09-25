#include "simple2drender.h"

namespace sparky {
	namespace graphics {
		void simple2drender::submit(const render2d* rendable) {
			m_renderque.push_back(rendable);
		}
		void simple2drender::flush() {
			while (!m_renderque.empty()) {
				const render2d* rendable = m_renderque.front();
				rendable->getVAO()->bind();
				rendable->getIBO()->bind();

				rendable->getshader().setUniformMat4("m1_matrix", (maths::mat4::translation(rendable->getPosition()))*(maths::mat4::translation(maths::vec3(-15,0,0))));
				glDrawElements(GL_TRIANGLES,rendable->getIBO()->getComponentCount(),GL_UNSIGNED_SHORT,0);

				rendable->getIBO()->unbind();
				rendable->getVAO()->unbind();

				m_renderque.pop_front();
			}
		}
	}
}