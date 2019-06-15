#include "Window.h"


void windowResized(GLFWwindow* window, int width, int height);


Window::Window(int width, int height, const char* title)
	:m_Width(width),m_Height(height),m_Title(title),m_Color{0,0,0,1.0f}
{
	if (!init())
		std::cout << "Failed to initialize window!" << std::endl;
	else std::cout << "Success!" << std::endl;
}

bool Window::init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
	if (!m_Window) {
		std::cout << "failed to initialize the window!" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetFramebufferSizeCallback(m_Window, windowResized);

	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
		std::cout << "failed to initlialize the glad!" << std::endl;
		return false;
	}

	return true;
}

bool Window::close() const {
	return glfwWindowShouldClose(m_Window) == 1;
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(m_Color[0], m_Color[1], m_Color[2], m_Color[3]);
}

void Window::bufferUpdate()const {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void windowResized(GLFWwindow* window, int width, int height) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	glfwGetFramebufferSize(win->m_Window, &win->m_Width, &win->m_Height);
	width = win->m_Width;
	height = win->m_Height;
	glViewport(0, 0, width, height);
}