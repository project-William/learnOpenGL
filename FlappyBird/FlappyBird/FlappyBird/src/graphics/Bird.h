#pragma once
#include "RenderObjects.h"

namespace flappy {
	namespace graphics {

		struct BirdPosition
		{
			float x, y;
		};


		class Bird :public RenderObjects {
		private:
			Mesh* bird_mesh;
			Shader* bird_shader;
			BirdPosition bd_pos = {0,0};
			int count;


			math::Matrix4f trans_bird = math::Matrix4f::identity();
			math::Matrix4f rot_bird = math::Matrix4f::identity();
			math::Matrix4f view_bird = math::Matrix4f::identity();


		public:

			Bird();
			void use(Window& window);

			Bird(const Bird& other) {
				delete this->bird_mesh;
				delete this->bird_shader;

				bird_mesh = other.bird_mesh;
				bird_shader = other.bird_shader;
			}

			Bird& operator=(const Bird& other) {
				delete this->bird_mesh;
				delete this->bird_shader;

				bird_mesh = other.bird_mesh;
				bird_shader = other.bird_shader;
				return *this;
			}


			~Bird();


		};
	}
}
