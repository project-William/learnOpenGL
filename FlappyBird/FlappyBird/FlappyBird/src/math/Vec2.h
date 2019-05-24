#pragma once
#include <math.h>

class Vec2 {
private:
	float m_X, m_Y;
public:
	Vec2():m_X(0),m_Y(0){}
	~Vec2(){}
	Vec2(const Vec2& other) {
		this->m_X = other.m_X;
		this->m_Y = other.m_Y;
	}

	Vec2& operator=(const Vec2& other) {
		this->m_X = other.m_X;
		this->m_Y = other.m_Y;
		return *this;
	}

	Vec2(float valuex, float valuey) :m_X(valuex), m_Y(valuey) {}

	void reset_x(float x) { m_X = x; }
	void reset_y(float y) { m_Y = y; }

	float get_x()const { return m_X; }
	float get_y()const { return m_Y; }


};
