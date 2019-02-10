#pragma once
#include <iostream>
#include <cmath>

template<class T> class Vec3 {
private:
	T x, y, z;
public:

	//vector constructor
	Vec3() { x = y = z = 0; }
	Vec3(T x_value, T y_value, T z_value) {
		x = x_value;
		y = y_value;
		z = z_value;
	}
	//reset & get
	void reset(T x_value, T y_value, T z_value) { x = x_value, y = y_value, z = z_value; }
	inline T get_x() const { return x; }
	inline T get_y() const { return y; }
	inline T get_z() const { return z; }
	inline T get_r() const { return x; }
	inline T get_g() const { return y; }
	inline T get_b() const { return z; }

	inline float magnitude() const { return sqrt(x*x + y * y + z * z); }

	//modify the single element of a vector
	inline void add_x(const T& value) { x += value; }
	inline void add_y(const T& value) { y += value; }
	inline void add_z(const T& value) { z += value; }

	inline void substract_x(const T& value) { x -= value; }
	inline void substract_y(const T& value) { y -= value; }
	inline void substract_z(const T& value) { z -= value; }

	inline void multiply_x(const T& value) { x *= value; }
	inline void multiply_y(const T& value) { y *= value; }
	inline void multiply_z(const T& value) { z *= value; }

	inline void divide_x(const T& value) { x /= value; }
	inline void divide_y(const T& value) { y /= value; }
	inline void divide_z(const T& value) { z /= value; }

	inline void add_r(const T& value) { x += value; }
	inline void add_g(const T& value) { y += value; }
	inline void add_b(const T& value) { z += value; }

	inline void substract_r(const T& value) { x -= value; }
	inline void substract_g(const T& value) { y -= value; }
	inline void substract_b(const T& value) { z -= value; }

	inline void multiply_r(const T& value) { x *= value; }
	inline void multiply_g(const T& value) { y *= value; }
	inline void multiply_b(const T& value) { z *= value; }

	inline void divide_r(const T& value) { x /= value; }
	inline void divide_g(const T& value) { y /= value; }
	inline void divide_b(const T& value) { z /= value; }

	//scale 
	inline void Scale_multi(const T& value) { x *= value, y *= value, z *= value; }
	inline void Scale_divide(const T& value) { T v = 1 / value; x *= v, y *= v, z *= v; }

	//overload operators
	inline const Vec3& operator+() const { return *this; }
	inline Vec3 operator+(const Vec3& other)const {
		return Vec3<T>(x + other.x, y + other.y, z + other.z);
	}

	inline Vec3& operator-() { x = -x, y = -y, z = -z; return *this; }
	inline Vec3 operator-(const Vec3& other) const {
		return Vec3<T>(x - other.x, y - other.y, z - other.z);
	}

	inline Vec3 operator*(const Vec3& other) const {
		return Vec3<T>(x*other.x, y*other.y, z*other.z);
	}

	inline Vec3 operator/(const Vec3& other) const {
		return Vec3<T>(x / other.x, y / other.y, z / other.z);
	}

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

	inline void normalize() {
		float k = 1.0f / sqrt(1.0f*(x * x + y * y + z * z));
		x *= k;
		y *= k;
		z *= k;
	}


};



