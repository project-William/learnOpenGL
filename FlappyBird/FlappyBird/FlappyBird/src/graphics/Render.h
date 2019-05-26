#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <list>
#include "Mesh.h"
#include "Window.h"
#include "utils/Input.h"
#include <random>
#include "Pipes.h"
#include "Bird.h"
#include "Background.h"

namespace flappy {
	namespace graphics {
		
		class Render {
		private:
			int pipeRef = 0;
			int mapp = 0;
			int pipeRef1 = 0;
		
			//pipes
			std::vector<Mesh*> pipes_mesh;
			std::vector<Mesh*> pipes_mesh1;


			//shader: background,bird,pipes
			std::vector<Shader*> pipes_shader;
			std::vector<Shader*> pipes_shader1;
			int flag = 0;
			//matrix4f
		
			math::Matrix4f translate = math::Matrix4f::identity();
			//bird position
		

			double z;


			std::vector<Pipes*> pipes;

			Background* bg;
			Pipes* pp;
			Bird* bird;

		public:
		

			Render();
			~Render();
			Render(const Render& other) = delete;
			Render& operator=(const Render& other) = delete;

			void renderBackground();
			void renderBird(Window& window);
			void renderPipes();

		};
	}
}
