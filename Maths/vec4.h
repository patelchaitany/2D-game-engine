#pragma once
#pragma once

#include<iostream>
namespace sparky {
	namespace maths {
		struct vec4
		{
			float x, y, z,w;
			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);

			friend vec4& operator+(vec4& left, const vec4& other);
			friend vec4& operator-(vec4& left, const vec4& other);
			friend vec4& operator*(vec4& left, const vec4& other);
			friend vec4& operator/(vec4& left, const vec4& other);
			friend bool operator==(const vec4& left, const vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};
	}
}