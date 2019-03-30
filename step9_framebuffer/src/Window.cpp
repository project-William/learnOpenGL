#include "Window.h"
#include <iostream>


void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void windowResized(GLFWwindow* window, int width, int height);


Window::Window(int width, int height, const char* title)
	:m_Width(width),m_Height(height),m_Title(title),
	camera(new Camera(glm::vec3(0.0f,0.0f,3.0f)))
{
	if (!init())
		std::cout << "Failed to initialize window!" << std::endl;
	else std::cout << "Success!" << std::endl;
}

Window::~Window()
{
}

void Window::update() const
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::closed()const {
	return glfwWindowShouldClose(m_Window) == 1;
}

bool Window::init()
{
	if (!glfwInit()) {
		std::cout << "Failed to initialzie GLFW!" << std::endl;
		return false;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
	if (!m_Window) {
		std::cout << "Failed to create a window!" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetFramebufferSizeCallback(m_Window, windowResized);
	glfwSetCursorPosCallback(m_Window, mouse_callback);
	glfwSetScrollCallback(m_Window, scroll_callback);

	glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
		std::cout << "Failed to initialize GLAD!" << std::endl;
		return false;
	}
	
	return true;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	if (win->firstMouse)
	{
		win->last_x = xpos;
		win->last_y = ypos;
		win->firstMouse = false;
	}

	float xoffset = xpos - win->last_x;
	float yoffset = win->last_y - ypos; 

	win->last_x = xpos;
	win->last_y = ypos;

	win->camera->processMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->camera->ProcessMouseScroll(yoffset);
}

void windowResized(GLFWwindow* window, int width, int height) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	glfwGetFramebufferSize(win->m_Window, &win->m_Width, &win->m_Height);
	glViewport(0, 0, win->m_Width, win->m_Height);
}
