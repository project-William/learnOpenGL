#pragma once
#include <iostream>

namespace math {
	class vec3 {
	private:
		float x, y, z;
	public:
		vec3():x(0),y(0),z(0) {}
		vec3(float xvalue, float yvalue, float zvalue) { x = xvalue, y = yvalue, z=zvalue; }
		
		float get_x()const { return x; }
		float get_y()const { return y; }
		float get_z()const { return z; }

		vec3& add(const vec3& other);
		vec3& substract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& divide(const vec3& other);

		friend vec3 operator+(const vec3& left, const vec3& right);
		friend vec3 operator-(const vec3& left, const vec3& right);
		friend vec3 operator*(const vec3& left, const vec3& right);
		friend vec3 operator/(const vec3& left, const vec3& right);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		friend std::ostream& operator<<(std::ostream& os, const vec3& vec);
	};


}