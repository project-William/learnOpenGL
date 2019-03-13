#include "vec4.h"

namespace math {
	vec4& math::vec4::add(const vec4& other){
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		return *this;
	}

	vec4& math::vec4::substract(const vec4& other){
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return *this;
	}

	vec4& math::vec4::multiply(const vec4& other){
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;
		return *this;
	}

	vec4& math::vec4::divide(const vec4& other){
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;
		return *this;
	}

	bool math::vec4::operator==(const vec4& other){
		return this->x == other.x && this->y == other.y
			&&this->z==other.z&&this->w==other.w;
	}

	bool math::vec4::operator!=(const vec4& other){
		return !(*this==other);
	}

	vec4& math::vec4::operator+=(const vec4& other){
		return add(other);
	}

	vec4& math::vec4::operator-=(const vec4& other){
		return substract(other);
	}

	vec4& math::vec4::operator*=(const vec4& other){
		return multiply(other);
	}

	vec4& math::vec4::operator/=(const vec4& other){
		return divide(other);
	}

	vec4 operator+(vec4& left, const vec4& right){
		return left.add(right);
	}

	vec4 operator-(vec4& left, const vec4& right){
		return left.substract(right);
	}

	vec4 operator*(vec4& left, const vec4& right){
		return left.multiply(right);
	}

	vec4 operator/(vec4& left, const vec4& right){
		return left.divide(right);
	}

	std::ostream& operator<<(std::ostream& os, const vec4& vec) {
		os << "vec4" << "(" << vec.x << "," << vec.y << "," << vec.z << "," << vec.w << std::endl;
	}

}