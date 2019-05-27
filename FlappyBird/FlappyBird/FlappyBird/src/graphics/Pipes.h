#pragma once
#include "math/Matrix4f.h"
#include "RenderObjects.h"

namespace flappy {
	namespace graphics{

		class Pipes :public RenderObjects{
		private:
			Mesh* pipe_mesh;
			Shader* pipe_shader;


			math::Matrix4f model = math::Matrix4f::identity();
			math::Matrix4f translate = math::Matrix4f::identity();
			math::Matrix4f rotate = math::Matrix4f::identity();

		public:
			Pipes();
			void setup(math::Matrix4f& view);

			Pipes(const Pipes& other) {
				delete this->pipe_mesh;
				delete this->pipe_shader;

				this->pipe_mesh = other.pipe_mesh;
				this->pipe_shader = other.pipe_shader;
			}

			Pipes& operator=(const Pipes& other) {
				delete this->pipe_mesh;
				delete this->pipe_shader;

				this->pipe_mesh = other.pipe_mesh;
				this->pipe_shader = other.pipe_shader;
				
				return *this;
			}

			~Pipes();
			void use();
		
		};
	}
}