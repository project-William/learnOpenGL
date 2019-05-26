#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <list>
#include "Mesh.h"
#include "Window.h"

namespace flappy {
	namespace graphics {

		struct BirdPosition {
			float x, y;
		};


		class Render {
		private:
			int map = 0;
			int xscroll = 0;
		
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

			std::vector<float> m_bird = {
				-0.05f,-0.05f,0.0f,
				 0.05f,-0.05f,0.0f,
				-0.05f, 0.05f,0.0f,
				-0.05f, 0.05f,0.0f,
				 0.05f,-0.05f,0.0f,
				 0.05f, 0.05f,0.0f,
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
			//bird
			Mesh* bird_mesh;


			//shader: background,bird,pipes
			Shader* bg_shader;
			Shader* bird_shader;

			//matrix4f
			math::Matrix4f trans_background = math::Matrix4f::identity();
			math::Matrix4f trans_bird = math::Matrix4f::identity();


			//bird position
			BirdPosition birdPos;
		public:

			Render();
			~Render();
			Render(const Render& other) = delete;
			Render& operator=(const Render& other) = delete;


			void update();
			void render(Window& window);
		};
	}
}
