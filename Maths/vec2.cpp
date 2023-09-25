#include "vec2.h"
namespace sparky {
	namespace maths {
		vec2::vec2() {
			x = 0;
			y = 0;
		}
		vec2::vec2(const float& x, const float& y) {
			this->x = x;
			this->y = y;
		}
		
		vec2& operator+( vec2 left, const vec2& other)
		{
			left.x += other.x;
			left.y += other.y;
			return left;
		}
		vec2& operator-( vec2 left, const vec2& other)
		{
			left.x -= other.x;
			left.y -= other.y;
			return left;
		}
		vec2& operator*( vec2 left, const vec2& other)
		{
			left.x *= other.x;
			left.y *= other.y;
			return left;
		}
		vec2& operator/( vec2 left, const vec2& other)
		{
			left.x /= other.x;
			left.y /= other.y;
			return left;
		}
		bool operator==(const vec2 left, const vec2 other){
			if (left.x == other.x && left.y == other.y) {
				return true;
			}
			return false;
		}
		std::ostream& operator<<(std::ostream& stream, const vec2& vector) {
			stream << "vec2:(" << vector.x << "," << vector.y << ")";
			return stream;
		}
	}
}