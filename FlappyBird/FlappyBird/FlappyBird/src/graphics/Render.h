#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <list>
#include "Mesh.h"
#include "Window.h"
#include "utils/Input.h"
#include <random>


namespace flappy {
	namespace graphics {
		struct BirdPosition {
			float x, y;
		};
		

		class Render {
		private:
			int map = 0;
			int xscroll = 0;
			int pipeRef = 0;
			int mapp = 0;
			int pipeRef1 = 0;
		
			std::vector<float> m_background = {
				-1.0f,-1.0f,0.0f,
				 0.0f,-1.0f,0.0f,
				-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,0.0f,
				 0.0f,-1.0f,0.0f,
				 0.0f, 1.0f,0.0f
			};


			std::vector<float> m_Pipes = {
				1.125f,-1.5f,0.0f,
				1.25f,-1.5f,0.0f,
				1.125f, 0.5f,0.0f,
				1.125f, 0.5f,0.0f,
				1.25f,-1.5f,0.0f,
				1.25f, 0.5f,0.0f,
			};
			
			std::vector<float> m_Pipes1 = {
				-0.875f,-1.5f,0.0f,
				-0.750f,-1.5f,0.0f,
				-0.875f, 0.5f,0.0f,
				-0.875f, 0.5f,0.0f,
				-0.750f,-1.5f,0.0f,
				-0.750f, 0.5f,0.0f,
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
			//bird
			Mesh* bird_mesh;
			//pipes
			std::vector<Mesh*> pipes_mesh;
			std::vector<Mesh*> pipes_mesh1;


			//shader: background,bird,pipes
			Shader* bg_shader;
			Shader* bird_shader;
			std::vector<Shader*> pipes_shader;
			std::vector<Shader*> pipes_shader1;
			int flag = 0;
			//matrix4f
			math::Matrix4f trans_background = math::Matrix4f::identity();
			math::Matrix4f trans_bird = math::Matrix4f::identity();
			math::Matrix4f rot_bird = math::Matrix4f::identity();
			math::Matrix4f bird_view = math::Matrix4f::identity();
			//matrix for pipes
			math::Matrix4f trans_pipes = math::Matrix4f::identity();
			math::Matrix4f rot_pipes = math::Matrix4f::identity();
			math::Matrix4f pipes_view = math::Matrix4f::identity();

			//bird position
			BirdPosition bd_pos = {0,0};
			int count = 0;
		
	

		public:
			float fall_begin_time=0.0f;
			float fall_end_time = 0.0f;

			Render();
			~Render();
			Render(const Render& other) = delete;
			Render& operator=(const Render& other) = delete;

			void renderBackground();
			void renderBird(Window& window);
			void renderPipes();

			void update();
		};
	}
}
