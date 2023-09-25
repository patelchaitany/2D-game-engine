#include "vec4.h"
namespace sparky {
	namespace maths {
		vec4::vec4() {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
		vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& operator+(vec4 left, const vec4& other)
		{
			left.x += other.x;
			left.y += other.y;
			left.z += other.z;
			left.w += other.w;
			return left;
		}
		vec4& operator-(vec4 left, const vec4& other)
		{
			left.x -= other.x;
			left.y -= other.y;
			left.z -= other.z;
			left.w -= other.w;
			return left;
		}
		vec4& operator*(vec4& left, const vec4& other)
		{
			left.x *= other.x;
			left.y *= other.y;
			left.z *= other.z;
			return left;
		}
		vec4& operator/(vec4 left, const vec4& other)
		{
			left.x /= other.x;
			left.y /= other.y;
			left.z /= other.z;
			left.w /= other.w;
			return left;
		}
		bool operator==(const vec4 left, const vec4 other) {
			if (left.x == other.x && left.y == other.y && left.z == other.z && left.w == other.w) {
				return true;
			}
			return false;
		}
		std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
			stream << "vec4:(" << vector.x << "," << vector.y << "," << vector.z <<","<<vector.w << ")";
			return stream;
		}
	}
}