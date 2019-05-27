#pragma once
#include "RenderObjects.h"

namespace flappy {
	namespace graphics {

		class Background :public RenderObjects {
		private:
			Mesh* bg_mesh;
			Shader* bg_shader;

			int map = 0;
			int xscroll = 0;

			math::Matrix4f trans_background = math::Matrix4f::identity();

		public:
			Background();
			Background(const Background& other) {
				delete this->bg_mesh;
				delete this->bg_shader;

				bg_mesh = other.bg_mesh;
				bg_shader = other.bg_shader;
			}

			Background& operator=(const Background& other) {
				delete this->bg_mesh;
				delete this->bg_shader;

				bg_mesh = other.bg_mesh;
				bg_shader = other.bg_shader;
				return *this;
			}

			~Background();

			void use();
		};
	}
}