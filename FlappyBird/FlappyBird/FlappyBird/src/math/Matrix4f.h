#pragma once
#include "math/Vec3.h"
#include "math/Vec4.h"
static const int ELE_SIZE = 16;

namespace flappy {
	namespace math {

		class Matrix4f {
		private:
			float m_Elements[16];
		public:
			Matrix4f() {}
			static Matrix4f identity() {
				Matrix4f mat4;
				for (int i = 0; i < ELE_SIZE; i++)
					mat4.m_Elements[i] = 0.0f;
				mat4.m_Elements[0 + 0 * 4] = 1.0f;
				mat4.m_Elements[1 + 1 * 4] = 1.0f;
				mat4.m_Elements[2 + 2 * 4] = 1.0f;
				mat4.m_Elements[3 + 3 * 4] = 1.0f;
				return mat4;
			}

			float& operator[](int index) {
				return m_Elements[index];
			}

			static Matrix4f orthographics(float l, float r, float t, float b, float n, float f) {
				Matrix4f mat4 = identity();
				mat4.m_Elements[0 + 0 * 4] = 2.0f / (r - l);
				mat4.m_Elements[1 + 1 * 4] = 2.0f / (t- b);
				mat4.m_Elements[2 + 2 * 4] = 2.0f / (n - f);

				mat4.m_Elements[3 + 0 * 4] = (l + r) / (l - r);
				mat4.m_Elements[3 + 1 * 4] = (t + b) / (b - t);
				mat4.m_Elements[3 + 2 * 4] = (f + n) / (n - f);
				
				return mat4;
			}
			

			static Matrix4f translate(const Vec3& vector3f) {
				Matrix4f mat4 = identity();

				mat4.m_Elements[0 + 3 * 4] = vector3f.get_x();
				mat4.m_Elements[1 + 3 * 4] = vector3f.get_y();
				mat4.m_Elements[2 + 3 * 4] = vector3f.get_z();

				return mat4;
			}


			static Matrix4f rotate(float angle) {
				Matrix4f mat4 = identity();
				float r = angle * M_PI / 180.0f;
				float cos = cosf(r);
				float sin = sinf(r);

				mat4.m_Elements[0 + 0 * 4] = cos;
				mat4.m_Elements[1 + 0 * 4] = -sin;
				mat4.m_Elements[0 + 1 * 4] = sin;
				mat4.m_Elements[1 + 1 * 4] = cos;

				return mat4;
			}

			static friend Matrix4f multiply(Matrix4f mat1, Matrix4f mat2);

		};

		static Matrix4f multiply(Matrix4f mat1, Matrix4f mat2) {
			Matrix4f mat4;
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += mat1.m_Elements[x + e * 4] * mat2.m_Elements[e + y * 4];
					}
					mat4.m_Elements[x + y * 4] = sum;
				}
			}
			return mat4;
		}

	}
}

