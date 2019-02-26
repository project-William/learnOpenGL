#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	if (win->firstMouse) {
		win->last_x = xpos;
		win->last_y = ypos;
		win->firstMouse = false;
	}
	float xoffset = xpos - win->last_x;
	float yoffset = win->last_y - ypos;

	win->last_x = xpos;
	win->last_y = ypos;

	win->camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->camera.ProcessMouseScroll(yoffset);
}


Window::Window(const char * title, int width, int height)
	:m_title(title),m_width(width),m_height(height),camera(Camera(glm::vec3(0.0f,0.0f,3.0f)))
{
	if (!glfwInit()) {
		std::cout << "Failed to initialzie GLFW!" << std::endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	if (!m_window) {
		std::cout << "Failed to create the window!" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	glfwSetCursorPosCallback(m_window, mouse_callback);
	glfwSetScrollCallback(m_window, scroll_callback);

	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
		std::cout << "Failed to initialize the GLAD!" << std::endl;
	}

}

void Window::update() const
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool Window::closed() const
{
	return glfwWindowShouldClose(m_window)==1;
}

void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::processInput(GLFWwindow * window)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, GLFW_TRUE);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		win->camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		win->camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		win->camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		win->camera.ProcessKeyboard(RIGHT, deltaTime);
}

