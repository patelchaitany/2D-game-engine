#include "vec3.h"
namespace sparky {
	namespace maths {
		vec3::vec3() {
			x = 0;
			y = 0;
			z = 0;
		}
		vec3::vec3(const float& x, const float& y,const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& operator+(vec3 left, const vec3& other)
		{
			left.x += other.x;
			left.y += other.y;
			left.z += other.z;
			return left;
		}
		vec3& operator-(vec3 left, const vec3& other)
		{
			left.x -= other.x;
			left.y -= other.y;
			left.z -= other.z;
			return left;
		}
		vec3& operator*(vec3& left, const vec3& other)
		{
			left.x *= other.x;
			left.y *= other.y;
			left.z *= other.z;
			return left;
		}
		vec3& operator/(vec3 left, const vec3& other)
		{
			left.x /= other.x;
			left.y /= other.y;
			left.z /= other.z;
			return left;
		}
		bool operator==(const vec3 left, const vec3 other) {
			if (left.x == other.x && left.y == other.y && left.z == other.z){
				return true;
			}
			return false;
		}
		std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
			stream << "vec3:(" << vector.x << "," << vector.y <<","<<vector.z << ")";
			return stream;
		}
	}
}