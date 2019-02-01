#include "Window.h"


Window::Window(int width, int height, const char*title) {
	m_Width = width;
	m_Height = height;
	m_Title = title;

	if (!Init())
		std::cout << "Failed to initialize window" << std::endl;
	else std::cout << "Success!" << std::endl;
}

bool Window::Init() {
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return false;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


	m_window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_window) {
		std::cout << "Failed to create window!" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_window);
	


	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
		std::cout << "Failed to initialize the GLAD!" << std::endl;
		return false;
	}



	return true;
}

bool Window::Closed() const {
	return glfwWindowShouldClose(m_window);
}

void Window::Clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void Window::Update() {
	glfwSwapBuffers(m_window);
	glfwPollEvents();
	WindowResized();
}

void Window::WindowResized() {
	glfwGetFramebufferSize(m_window, &m_Width, &m_Height);
	glViewport(0, 0, m_Width, m_Height);
}

void Window::ProcessInput() const {
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, GL_TRUE);
}



Window::~Window() {
	glfwTerminate();
}