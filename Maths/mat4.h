#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "vec3.h"
#include "vec4.h"
namespace sparky {
	namespace maths {
		struct mat4 {
			union {
				float elements[4 * 4];
				vec4 cloums[4];
			};
			
			mat4();
			mat4(float diagonal);
			static float rnd(float deg);
			static mat4 identity();
			static mat4 orthographic(float left,float right,float bottom,float top,float near,float far);
			static mat4 prespictive(float fov, float aspectRation, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3 axis);
			static mat4 scale(const vec3& scale);

			friend mat4 operator*(mat4 left, const mat4& right);
			
		};
	}
}