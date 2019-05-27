#include "Window.h"
#include <iostream>

bool Window::m_MouseButtons[MAX_BUTTONS];
bool Window::m_Keys[MAX_KEYS];

void windowResized(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
void curorPos_callback(GLFWwindow* window, double xpos, double ypos);


Window::Window(int width, int height, const char* title)
	:m_Width(width), m_Height(height), m_Title(title)
	, m_Camera(new Camera(glm::vec3(0.0f,0.0f,3.0f)))
{
	if (!init())
		std::cout << "Failed to create window!" << std::endl;
	else std::cout << "Success!" << std::endl;

	for (int i = 0; i < 1024; i++) {
		m_Keys[i] = false;
	}

	for (int i = 0; i < 32; i++) {
		m_MouseButtons[i] = false;
	}

}

bool Window::isKeyPressed(unsigned int keycode) {
	if (keycode >= MAX_KEYS)
		return false;
	else
		return m_Keys[keycode];
}

bool Window::isMouseButtonPressed(unsigned int button) {
	if (button >= MAX_BUTTONS)
		return false;
	else
		return m_MouseButtons[button];
}


void Window::clear()const {
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::close()const {
	return glfwWindowShouldClose(m_Window);
}

void Window::update() {
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Window::frameTime() {
	m_CurrentFrame = glfwGetTime();
	m_DeltaTime = m_CurrentFrame - m_LastFrame;
	m_LastFrame = m_CurrentFrame;
}

bool Window::init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
	if (!m_Window) {
		std::cout << "Failed to initialize the window!" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetWindowSizeCallback(m_Window, windowResized);
	glfwSetKeyCallback(m_Window, key_callback);
	glfwSetCursorPosCallback(m_Window, curorPos_callback);

	glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
		std::cout << "Failed to initialize GLAD!" << std::endl;
		glfwTerminate();
		return false;
	}


	return true;

}


void windowResized(GLFWwindow* window, int width, int height) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	glfwGetFramebufferSize(win->m_Window, &win->m_Width, &win->m_Height);
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Keys[key] = action != GLFW_RELEASE;
}

void mouseButton_callback(GLFWwindow* window, int button, int action, int mods) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_MouseButtons[button] = action != GLFW_RELEASE;
}

void curorPos_callback(GLFWwindow* window, double xpos, double ypos) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	
	if (win->firstMouse)
	{
		win->lastX = xpos;
		win->lastY = ypos;
		win->firstMouse = false;
	}

	float xoffset = xpos - win->lastX;
	float yoffset = win->lastY - ypos; 

	win->lastX = xpos;
	win->lastY = ypos;

	win->getCamera()->ProcessMouseMovement(xoffset, yoffset);
}













