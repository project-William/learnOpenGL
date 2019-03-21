#include "Window.h"

namespace GLfw {
	Window::Window():m_Width(0),m_Height(0),m_Title(""),m_Window(nullptr){}
	
	Window* Window::instance = new Window();

	Window* Window::GetInstance() { return instance; }
	
	bool Window::closed()const {
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::Init(int width, int height, const char* title) {
		m_Width = width;
		m_Height = height;
		m_Title = title;
		
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		createWindow();

		glfwMakeContextCurrent(m_Window);
		
		loadGL();

	}

	void Window::createWindow() {
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
		if (!m_Window) {
			std::cout << "Failed to create window!" << std::endl;
			glfwTerminate();
			exit(1);
		}
	}

	void Window::loadGL()const {
		if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
			std::cout << "Failed to initialize the glad!" << std::endl;
			exit(1);
		}
	}

	void Window::update()const {
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::Terminate()const {
		glfwTerminate();
	}

	void Window::Run()const {
		while (!instance->closed()) {
			instance->update();
		}
	}
}