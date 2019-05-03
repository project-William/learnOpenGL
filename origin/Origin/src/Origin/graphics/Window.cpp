#include "Window.h"
#include <iostream>
namespace origin {
	namespace graphics {
		

		Window::Window(int width, int height, const char* title)
			:m_WinPro({width,height,title,nullptr})
		{
			if (!init())
				std::cout << "Failed to initialize window!" << std::endl;
			else std::cout << "Success!" << std::endl;
		}

		void Window::update()
		{
			glfwSwapBuffers(m_WinPro.m_Window);
			glfwPollEvents();
		}

		bool Window::init()
		{
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_WinPro.m_Window = glfwCreateWindow(m_WinPro.m_Width, m_WinPro.m_Height, m_WinPro.m_Title, nullptr, nullptr);
			if (!m_WinPro.m_Window) {
				std::cout << "Failed to initialize a window!" << std::endl;
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(m_WinPro.m_Window);

			if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
				std::cout << "Failed to initialize the GLAD!" << std::endl;
				glfwTerminate();
				return false;
			}

			return true;
		}
		
		bool Window::close()
		{
			return glfwWindowShouldClose(m_WinPro.m_Window);
		}

	}
}