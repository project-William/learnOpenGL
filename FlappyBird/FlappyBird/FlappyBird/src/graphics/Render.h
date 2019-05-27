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
			//matrix4f
			math::Matrix4f translate = math::Matrix4f::identity();
			math::Matrix4f rotate = math::Matrix4f::identity();
			math::Matrix4f view = math::Matrix4f::identity();

			std::vector<float> randomup;
			std::vector<float> randombottom;
			
			std::vector<float> randomup1;
			std::vector<float> randombottom1;

			std::vector<Pipes*> pipes;

			Background* bg;
			Bird* bird;

			int ref = 0;
			int ref1 = 0;
			int delay = 0;

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
