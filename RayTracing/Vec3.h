#pragma once
#include <iostream>
#include <cmath>

class Vec3 {
private:
	float x, y, z;
public:

	//vector constructor
	Vec3() { x = y = z = 0; }
	Vec3(float x_value, float y_value, float z_value) {
		x = x_value;
		y = y_value;
		z = z_value;
	}
	//reset & get
	void reset(float x_value, float y_value, float z_value) { x = x_value, y = y_value, z = z_value; }
	inline float get_x() const { return x; }
	inline float get_y() const { return y; }
	inline float get_z() const { return z; }
	inline float get_r() const { return x; }
	inline float get_g() const { return y; }
	inline float get_b() const { return z; }

	inline float magnitude() const { return sqrt(x*x + y * y + z * z); }

	//modify the single element of a vector
	inline void add_x(const float& value) { x += value; }
	inline void add_y(const float& value) { y += value; }
	inline void add_z(const float& value) { z += value; }

	inline void substract_x(const float& value) { x -= value; }
	inline void substract_y(const float& value) { y -= value; }
	inline void substract_z(const float& value) { z -= value; }

	inline void multiply_x(const float& value) { x *= value; }
	inline void multiply_y(const float& value) { y *= value; }
	inline void multiply_z(const float& value) { z *= value; }

	inline void divide_x(const float& value) { x /= value; }
	inline void divide_y(const float& value) { y /= value; }
	inline void divide_z(const float& value) { z /= value; }

	inline void add_r(const float& value) { x += value; }
	inline void add_g(const float& value) { y += value; }
	inline void add_b(const float& value) { z += value; }

	inline void substract_r(const float& value) { x -= value; }
	inline void substract_g(const float& value) { y -= value; }
	inline void substract_b(const float& value) { z -= value; }

	inline void multiply_r(const float& value) { x *= value; }
	inline void multiply_g(const float& value) { y *= value; }
	inline void multiply_b(const float& value) { z *= value; }

	inline void divide_r(const float& value) { x /= value; }
	inline void divide_g(const float& value) { y /= value; }
	inline void divide_b(const float& value) { z /= value; }

	//scale 
	inline void Scale_multi(const float& value) { x *= value, y *= value, z *= value; }
	inline void Scale_divide(const float& value) { float v = 1 / value; x *= v, y *= v, z *= v; }


	//overload operators

	inline Vec3& operator+=(const Vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	inline Vec3& operator-=(const Vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}


	inline Vec3& operator*=(const Vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	inline Vec3& operator/=(const Vec3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	inline void display() { std::cout << "X:" << x << " " << "Y:" << y << " " << "Z:" << z << std::endl; }

	inline float distance(const Vec3& other) {
		float dx = x - other.x;
		float dy = y - other.y;
		float dz = z - other.z;
		return sqrt(dx*dx + dy * dy + dz * dz);
	}

	inline Vec3& normalize() {
		float k = 1.0f / sqrt(1.0f*(x * x + y * y + z * z));
		x *= k;
		y *= k;
		z *= k;
		return *this;
	}

	friend inline Vec3 operator*(const Vec3& v, float t);
	friend inline Vec3 operator*(float t, const Vec3& v);
	friend inline Vec3 operator/(const Vec3& v, float t);

	friend inline Vec3 operator+(const Vec3& v1, const Vec3& v2);
	friend inline Vec3 operator-(const Vec3& v1, const Vec3& v2);
	friend inline Vec3 operator*(const Vec3& v1, const Vec3& v2);
	friend inline Vec3 operator/(const Vec3& v1, const Vec3& v2);

	//product
	friend float dot(const Vec3& v1, const Vec3& v2);
	friend Vec3 cross(const Vec3& v1, const Vec3& v2);
};

inline Vec3 operator+(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vec3 operator*(float t, const Vec3& v ) {
	return Vec3(t*v.x, t*v.y, t*v.z);
}

inline Vec3 operator*(const Vec3& v, float t) {
	return Vec3(v.x*t, v.y*t, v.z*t);
}

inline Vec3 operator/(const Vec3& v, float t) {
	return Vec3(v.x / t, v.y / t, v.z / t);
}


inline Vec3 operator-(const Vec3& v1, const Vec3& v2){
	return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2){
	return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline Vec3 operator/(const Vec3& v1, const Vec3& v2){
	return Vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

float dot(const Vec3& v1, const Vec3& v2) {
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vec3 cross(const Vec3& v1, const Vec3& v2) {
	return Vec3(
		v1.y*v2.z - v1.z*v2.y,
		-(v1.x*v2.z - v1.z*v2.x),
		v1.x*v2.y - v1.y*v2.x
	);
}