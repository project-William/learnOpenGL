#include "vec2.h"

namespace math {
	vec2& math::vec2::add(const vec2& other){
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	vec2& math::vec2::substract(const vec2& other){
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	vec2& math::vec2::multiply(const vec2& other){
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	vec2& math::vec2::divide(const vec2& other){
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	bool math::vec2::operator==(const vec2& other){
		return this->x == other.x && this->y == other.y;
	}

	bool math::vec2::operator!=(const vec2& other){
		return !(*this==other);
	}

	vec2& math::vec2::operator+=(const vec2& other){
		return add(other);
	}

	vec2& math::vec2::operator-=(const vec2& other){
		return substract(other);
	}

	vec2& math::vec2::operator*=(const vec2& other){
		return multiply(other);
	}

	vec2& math::vec2::operator/=(const vec2& other){
		return divide(other);
	}

	vec2 operator+(vec2& left, const vec2& right){
		return left.add(right);
	}

	vec2 operator-(vec2& left, const vec2& right){
		return left.substract(right);
	}

	vec2 operator*(vec2& left, const vec2& right){
		return left.multiply(right);
	}

	vec2 operator/(vec2& left, const vec2& right){
		return left.divide(right);
	}

	std::ostream& operator<<(std::ostream& os, const vec2& vec) {
		os << "vec2" << "(" << vec.x << "," << vec.y << ")" << std::endl;
	}

}