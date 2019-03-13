#pragma once
#include <iostream>

namespace math {
	class vec2 {
	private:
		float x, y;
	public:
		vec2():x(0),y(0) {}
		vec2(float xvalue, float yvalue) { x = xvalue, y = yvalue; }
		
		float get_x()const { return x; }
		float get_x()const { return y; }

		vec2& add(const vec2& other);
		vec2& substract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& divide(const vec2& other);

		friend vec2 operator+(const vec2& left, const vec2& right);
		friend vec2 operator-(const vec2& left, const vec2& right);
		friend vec2 operator*(const vec2& left, const vec2& right);
		friend vec2 operator/(const vec2& left, const vec2& right);

		bool operator==(const vec2& other);
		bool operator!=(const vec2& other);

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		friend std::ostream& operator<<(std::ostream& os, const vec2& vec);
	};


}