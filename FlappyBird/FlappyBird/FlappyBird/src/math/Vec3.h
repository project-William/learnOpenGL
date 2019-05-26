#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace flappy {
	namespace math {
		class Vec3 {
		private:
			float m_X, m_Y, m_Z;
		public:
			Vec3() :m_X(0), m_Y(0), m_Z(0){}
			~Vec3() {}
			Vec3(const Vec3& other) {
				this->m_X = other.m_X;
				this->m_Y = other.m_Y;
				this->m_Z = other.m_Z;
			}
			Vec3(float value):m_X(value),m_Y(value),m_Z(value){}
			Vec3(float valuex, float valuey, float valuez) :m_X(valuex), m_Y(valuey), m_Z(valuez){}

			inline void reset_x(float x) { m_X = x; }
			inline void reset_y(float y) { m_Y = y; }
			inline void reset_z(float z) { m_Z = z; }

			inline float get_x()const { return m_X; }
			inline float get_y()const { return m_Y; }
			inline float get_z()const { return m_Z; }

			inline Vec3& operator=(const Vec3& other) {
				this->m_X = other.m_X;
				this->m_Y = other.m_Y;
				this->m_Z = other.m_Z;
				return *this;
			}

			inline bool operator==(const Vec3& other) {
				return other.m_X == this->m_X && other.m_Y == this->m_Y&& other.m_Z==this->m_Z
					? true
					: false;
			}

			inline Vec3& operator+=(const Vec3& other) {
				this->m_X += other.m_X;
				this->m_Y += other.m_Y;
				this->m_Z += other.m_Z;
				return *this;
			}

			inline Vec3& operator-=(const Vec3& other) {
				this->m_X -= other.m_X;
				this->m_Y -= other.m_Y;
				this->m_Z -= other.m_Z;
				return *this;
			}

			inline Vec3& operator*=(const float f) {
				this->m_X *= f;
				this->m_Y *= f;
				this->m_Z *= f;
				return *this;
			}

			inline Vec3& operator/=(const float f) {
				this->m_X /= f;
				this->m_Y /= f;
				this->m_Z /= f;
				return *this;
			}

			friend inline Vec3 operator+(const Vec3& v1, const Vec3& v2);
			friend inline Vec3 operator-(const Vec3& v1, const Vec3& v2);
			friend inline Vec3 operator*(const Vec3& v1, const float f);
			friend inline Vec3 operator*(const float f, const Vec3& v1);
			friend inline Vec3 operator/(const Vec3& v1, const float f);


			inline float mod() const {
				return sqrtf(powf(this->m_X, 2) + powf(this->m_Y, 2) + powf(this->m_Z,2));
			}

			inline Vec3& normalised() {
				float length = this->mod();
				*this /= length;
				return *this;
			}
		};


		inline Vec3 operator+(const Vec3& v1, const Vec3& v2) {
			return Vec3(v1.m_X + v2.m_X, v1.m_Y + v2.m_Y, v1.m_Z + v2.m_Z);
		}

		inline Vec3 operator-(const Vec3 & v1, const Vec3 & v2) {
			return Vec3(v1.m_X - v2.m_X, v1.m_Y - v2.m_Y, v1.m_Z - v2.m_Z);
		}

		inline Vec3 operator*(const Vec3 & v1, const float f) {
			return Vec3(v1.m_X * f, v1.m_Y * f, v1.m_Z * f);
		}

		inline Vec3 operator*(const float f, const Vec3 & v1) {
			return Vec3(f * v1.m_X, f * v1.m_Y, f * v1.m_Z);
		}

		inline Vec3 operator/(const Vec3 & v1, const float f) {
			return Vec3(v1.m_X / f, v1.m_Y / f, v1.m_Z / f);
		}

		static float dot(const Vec3 & v1, const Vec3 & v2) {
			return v1.get_x()* v2.get_x() + v1.get_y() * v2.get_y() + v1.get_z() * v2.get_z();
		}

		static float getRadians(const Vec3 & v1, const Vec3 & v2) {
			return acos(dot(v1, v2) / (v1.mod() * v2.mod()));
		}

		static float getDegrees(const Vec3 & v1, const Vec3 & v2) {
			return acos(dot(v1, v2) / (v1.mod() * v2.mod())) * (180.0f / M_PI);
		}
	}
}

