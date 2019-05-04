#pragma once
#include <iostream>
#include "Origin/Core.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Origin/utils/ReadFile.h"
namespace origin {
	namespace graphics {
		struct WindowPros {
			int m_Width = 800;
			int m_Height = 600;
			const char* m_Title = "origin";
			GLFWwindow* m_Window = nullptr;
		};


		class ORIGIN_API Window {
		private:
			WindowPros m_WinPro;
		public:
			Window(){}
			~Window(){}
			Window(int width, int height, const char* title);

			void update();
			bool close();

			inline int getWidth()const { return m_WinPro.m_Width; }
			inline int getHeight()const { return m_WinPro.m_Height; }
			inline WindowPros getPros()const { return m_WinPro; }
		private:
			bool init();
		};
	}
}