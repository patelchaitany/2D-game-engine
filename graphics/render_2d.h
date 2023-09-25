#pragma once
#include"rander2d.h"
#include "GL/glew.h"
#include"Maths/vec2.h"
#include"Maths/vec3.h"
#include"Maths/vec4.h"
namespace sparky {
	namespace graphics {
		class rend2d {
		public:
			virtual void submit(const render2d* rendable) = 0;
			virtual void flush() = 0;
	};
	}
}