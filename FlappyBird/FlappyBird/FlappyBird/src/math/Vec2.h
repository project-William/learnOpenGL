#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace flappy {
	namespace math {
		class Vec2 {
		private:
			float m_X, m_Y;
		public:
			Vec2() :m_X(0), m_Y(0) {}
			~Vec2() {}
			Vec2(const Vec2& other) {
				this->m_X = other.m_X;
				this->m_Y = other.m_Y;
			}

			Vec2(float valuex, float valuey) :m_X(valuex), m_Y(valuey) {}

			inline void reset_x(float x) { m_X = x; }
			inline void reset_y(float y) { m_Y = y; }

			inline float get_x()const { return m_X; }
			inline float get_y()const { return m_Y; }

			inline Vec2& operator=(const Vec2& other) {
				this->m_X = other.m_X;
				this->m_Y = other.m_Y;
				return *this;
			}

			inline bool operator==(const Vec2& other) {
				return other.m_X == this->m_X && other.m_Y == this->m_Y
					? true
					: false;
			}

			inline Vec2& operator+=(const Vec2& other) {
				this->m_X += other.m_X;
				this->m_Y += other.m_Y;
				return *this;
			}

			inline Vec2& operator-=(const Vec2& other) {
				this->m_X -= other.m_X;
				this->m_Y -= other.m_Y;
				return *this;
			}

			inline Vec2& operator*=(const float f) {
				this->m_X *= f;
				this->m_Y *= f;
				return *this;
			}

			inline Vec2& operator/=(const float f) {
				this->m_X /= f;
				this->m_Y /= f;
				return *this;
			}

			friend inline Vec2 operator+(const Vec2& v1, const Vec2& v2);
			friend inline Vec2 operator-(const Vec2& v1, const Vec2& v2);
			friend inline Vec2 operator*(const Vec2& v1, const float f);
			friend inline Vec2 operator*(const float f, const Vec2& v1);
			friend inline Vec2 operator/(const Vec2& v1, const float f);


			inline float mod() const {
				return sqrtf(powf(this->m_X, 2) + powf(this->m_Y, 2));
			}

			inline Vec2& normalised() {
				float length = this->mod();
				*this /= length;
				return *this;
			}
		};


		inline Vec2 operator+(const Vec2& v1, const Vec2& v2) {
			return Vec2(v1.m_X + v2.m_X, v1.m_Y + v2.m_Y);
		}

		inline Vec2 operator-(const Vec2 & v1, const Vec2 & v2) {
			return Vec2(v1.m_X - v2.m_X, v1.m_Y - v2.m_Y);
		}

		inline Vec2 operator*(const Vec2 & v1, const float f) {
			return Vec2(v1.m_X * f, v1.m_Y * f);
		}

		inline Vec2 operator*(const float f, const Vec2 & v1) {
			return Vec2(f * v1.m_X, f * v1.m_Y);
		}

		inline Vec2 operator/(const Vec2 & v1, const float f) {
			return Vec2(v1.m_X / f, v1.m_Y / f);
		}

		static float dot(const Vec2 & v1, const Vec2 & v2) {
			return v1.get_x()* v2.get_x() + v1.get_y() * v2.get_y();
		}

		static float getRadians(const Vec2 & v1, const Vec2 & v2) {
			return acos(dot(v1, v2) / (v1.mod() * v2.mod()));
		}

		static float getDegrees(const Vec2 & v1, const Vec2 & v2) {
			return acos(dot(v1, v2) / (v1.mod() * v2.mod())) * (180.0f / M_PI);
		}
	}
}

