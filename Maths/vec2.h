#pragma once

#include<iostream>
namespace sparky {
	namespace maths {
		struct vec2
		{
			float x, y;
			vec2();
			vec2(const float &x,const float &y);

			friend vec2& operator+( vec2 left,const vec2& other);
			friend vec2& operator-( vec2 left,const vec2& other);
			friend vec2& operator*( vec2 left,const vec2& other);
			friend vec2& operator/( vec2 left,const vec2& other);
			friend bool operator==(const vec2 left,const vec2& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};
	}
}