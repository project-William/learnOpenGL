#pragma once
#include <glad/glad.h>
#include <vector>
#include <list>
#include "Mesh.h"


namespace flappy {
	namespace graphics {
		class Render {
		private:
			int map = 0;
			int xscroll = 0;
			int pipescroll = 0;
			int pipem = 0;
			std::vector<float> m_background = {
				-1.0f,-1.0f,0.0f,
				 0.0f,-1.0f,0.0f,
				-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,0.0f,
				 0.0f,-1.0f,0.0f,
				 0.0f, 1.0f,0.0f
			};


			std::vector<float> m_Pipes = {
				1.0f,-1.0f,0.0f,
				1.15f,-1.0f,0.0f,
				1.0f, 0.0f,0.0f,
				1.0f, 0.0f,0.0f,
				1.15f,-1.0f,0.0f,
				1.15f, 0.0f,0.0f,
			};

			std::vector<float> m_TexCoord = {
				0.0f,0.0f,
				1.0f,0.0f,
				0.0f,1.0f,
				0.0f,1.0f,
				1.0f,0.0f,
				1.0f,1.0f
			};
			//mesh part background ,bird , pipes
			//background
			Mesh* bg_mesh;
			//pipes
			Mesh* pipe_mesh;

			//shader: background,bird,pipes
			Shader* bg_shader;
			Shader* pipe_shader;
			//matrix4f
			math::Matrix4f tran = math::Matrix4f::identity();
			math::Matrix4f trans = math::Matrix4f::identity();
		public:

			Render();
			~Render();
			Render(const Render& other) = delete;
			Render& operator=(const Render& other) = delete;


			void update();
			void renderBackground();
			void render();
		};
	}
}
