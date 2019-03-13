#pragma once
#include <iostream>

namespace math {
	class vec4 {
	private:
		float x, y, z, w;
	public:
		vec4():x(0),y(0),z(0),w(0) {}
		vec4(float xvalue, float yvalue, float zvalue, float wvalue) { 
			x = xvalue, y = yvalue, z=zvalue, w=wvalue; 
		}
		
		float get_x()const { return x; }
		float get_y()const { return y; }
		float get_z()const { return z; }
		float get_w()const { return w; }

		vec4& add(const vec4& other);
		vec4& substract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& divide(const vec4& other);

		friend vec4 operator+(const vec4& left, const vec4& right);
		friend vec4 operator-(const vec4& left, const vec4& right);
		friend vec4 operator*(const vec4& left, const vec4& right);
		friend vec4 operator/(const vec4& left, const vec4& right);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		friend std::ostream& operator<<(std::ostream& os, const vec4& vec);
	};


}