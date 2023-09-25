#pragma once
#include "render_2d.h"
#include<deque>
namespace sparky {
	namespace graphics {
		class simple2drender : public rend2d {
		private:
			std::deque<const render2d*> m_renderque;
		public:
			void submit(const render2d* rendable) override;
			void flush() override;
		};
	}
}