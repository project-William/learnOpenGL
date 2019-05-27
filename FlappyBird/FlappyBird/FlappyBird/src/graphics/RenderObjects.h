#pragma once
#include <vector>
#include "Mesh.h"
#include "Window.h"
namespace flappy {
	namespace graphics {

		class RenderObjects {
		protected:
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
		};
	}
}