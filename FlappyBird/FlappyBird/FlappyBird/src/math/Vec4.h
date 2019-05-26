#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace flappy {
	namespace math {
		class Vec4 {
		private:
			float m_X, m_Y, m_Z, m_W;
		public:
			Vec4() :m_X(0), m_Y(0), m_Z(0), m_W(0) {}
			~Vec4() {}
			Vec4(const Vec4& other) {
				this->m_X = other.m_X;
				this->m_Y = other.m_Y;
				this->m_Z = other.m_Z;
				this->m_W = other.m_W;
			}
			Vec4(float value) :m_X(value), m_Y(value), m_Z(value), m_W(value) {}
			Vec4(float valuex, float valuey, float valuez, float valuew) 
				:m_X(valuex), m_Y(valuey), m_Z(valuez) ,m_W(valuew){}

			inline void reset_x(float x) { m_X = x; }
			inline void reset_y(float y) { m_Y = y; }
			inline void reset_Z(float z) { m_Z = z; }
			inline void reset_W(float w) { m_W = w; }

			inline float get_x()const { return m_X; }
			inline float get_y()const { return m_Y; }
			inline float get_z()const { return m_Z; }
			inline float get_w()const { return m_W; }

			inline Vec4& operator=(const Vec4& other) {
				this->m_X = other.m_X;
				this->m_Y = other.m_Y;
				this->m_Z = other.m_Z;
				this->m_W = other.m_W;
				return *this;
			}

			inline bool operator==(const Vec4& other) {
				return other.m_X == this->m_X && other.m_Y == this->m_Y 
					&& other.m_Z == this->m_Z && other.m_W==this->m_W
					? true
					: false;
			}

			inline Vec4& operator+=(const Vec4& other) {
				this->m_X += other.m_X;
				this->m_Y += other.m_Y;
				this->m_Z += other.m_Z;
				this->m_W += other.m_W;
				return *this;
			}

			inline Vec4& operator-=(const Vec4& other) {
				this->m_X -= other.m_X;
				this->m_Y -= other.m_Y;
				this->m_Z -= other.m_Z;
				this->m_W -= other.m_W;
				return *this;
			}

			inline Vec4& operator*=(const float f) {
				this->m_X *= f;
				this->m_Y *= f;
				this->m_Z *= f;
				this->m_W *= f;
				return *this;
			}

			inline Vec4& operator/=(const float f) {
				this->m_X /= f;
				this->m_Y /= f;
				this->m_Z /= f;
				this->m_W /= f;
				return *this;
			}

			friend inline Vec4 operator+(const Vec4& v1, const Vec4& v2);
			friend inline Vec4 operator-(const Vec4& v1, const Vec4& v2);
			friend inline Vec4 operator*(const Vec4& v1, const float f);
			friend inline Vec4 operator*(const float f, const Vec4& v1);
			friend inline Vec4 operator/(const Vec4& v1, const float f);


			inline float mod() const {
				return sqrtf(powf(this->m_X, 2) + powf(this->m_Y, 2) + powf(this->m_Z, 2) + powf(this->m_W, 2));
			}

			inline Vec4& normalised() {
				float length = this->mod();
				*this /= length;
				return *this;
			}
		};


		inline Vec4 operator+(const Vec4& v1, const Vec4& v2) {
			return Vec4(v1.m_X + v2.m_X, v1.m_Y + v2.m_Y, v1.m_Z + v2.m_Z, v1.m_W + v2.m_W);
		}

		inline Vec4 operator-(const Vec4 & v1, const Vec4 & v2) {
			return Vec4(v1.m_X - v2.m_X, v1.m_Y - v2.m_Y, v1.m_Z - v2.m_Z, v1.m_W - v2.m_W);
		}

		inline Vec4 operator*(const Vec4 & v1, const float f) {
			return Vec4(v1.m_X * f, v1.m_Y * f, v1.m_Z * f, v1.m_W * f);
		}

		inline Vec4 operator*(const float f, const Vec4 & v1) {
			return Vec4(f * v1.m_X, f * v1.m_Y, f * v1.m_Z, f * v1.m_W);
		}

		inline Vec4 operator/(const Vec4 & v1, const float f) {
			return Vec4(v1.m_X / f, v1.m_Y / f, v1.m_Z / f, v1.m_W / f);
		}

		static float dot(const Vec4 & v1, const Vec4 & v2) {
			return v1.get_x()* v2.get_x() + v1.get_y() * v2.get_y() + v1.get_z() * v2.get_z() + v1.get_w() * v2.get_w();
		}

		static float getRadians(const Vec4 & v1, const Vec4 & v2) {
			return acos(dot(v1, v2) / (v1.mod() * v2.mod()));
		}

		static float getDegrees(const Vec4 & v1, const Vec4 & v2) {
			return acos(dot(v1, v2) / (v1.mod() * v2.mod())) * (180.0f / M_PI);
		}
	}
}

