#include "vec3.h"

namespace math {
	vec3& math::vec3::add(const vec3& other){
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}

	vec3& math::vec3::substract(const vec3& other){
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return *this;
	}

	vec3& math::vec3::multiply(const vec3& other){
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		return *this;
	}

	vec3& math::vec3::divide(const vec3& other){
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		return *this;
	}

	bool math::vec3::operator==(const vec3& other){
		return this->x == other.x && this->y == other.y && this->z==other.z;
	}

	bool math::vec3::operator!=(const vec3& other){
		return !(*this==other);
	}

	vec3& math::vec3::operator+=(const vec3& other){
		return add(other);
	}

	vec3& math::vec3::operator-=(const vec3& other){
		return substract(other);
	}

	vec3& math::vec3::operator*=(const vec3& other){
		return multiply(other);
	}

	vec3& math::vec3::operator/=(const vec3& other){
		return divide(other);
	}

	vec3 operator+(vec3& left, const vec3& right){
		return left.add(right);
	}

	vec3 operator-(vec3& left, const vec3& right){
		return left.substract(right);
	}

	vec3 operator*(vec3& left, const vec3& right){
		return left.multiply(right);
	}

	vec3 operator/(vec3& left, const vec3& right){
		return left.divide(right);
	}

	std::ostream& operator<<(std::ostream& os, const vec3& vec) {
		os << "vec3:" << "(" << vec.x << "," << vec.y << "," << vec.z << std::endl;
	}

}