#pragma once

#include<iostream>
namespace sparky {
	namespace maths {
		struct vec3
		{
			float x, y,z;
			vec3();
			vec3(const float& x, const float& y,const float& z);

			friend vec3& operator+(vec3& left, const vec3& other);
			friend vec3& operator-(vec3& left, const vec3& other);
			friend vec3& operator*(vec3& left, const vec3& other);
			friend vec3& operator/(vec3& left, const vec3& other);
			friend bool operator==(const vec3& left, const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}