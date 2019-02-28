#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	glViewport(0, 0, width, height);
}



Window::Window(const char * title, int width, int height)
	:m_Title(title),m_Width(width),m_height(height)
{
	if (init()) 
		std::cout << "Success!" << std::endl;
	else std::cout << "Failed to initialize window!" << std::endl;
}


bool Window::init() {
	if (!glfwInit()) {
		std::cout << "Failed to initialize the GLFW!" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(m_Width, m_height, m_Title, nullptr, nullptr);
	if (!m_Window) {
		std::cout << "Failed to create a window!" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
		std::cout << "Failed to initialize GLAD!" << std::endl;
		glfwTerminate();
		return false;
	}
	return true;

}

bool Window::closed()const {
	return glfwWindowShouldClose(m_Window) == 1;
}

void Window::update()const {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}


Window::~Window() {
	glfwTerminate();
}