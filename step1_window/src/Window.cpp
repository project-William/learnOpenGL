#include "Window.h"

void windowResized(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

Window::Window(unsigned int width, unsigned int height, const char* title)
	:m_Width(width),m_Height(height),m_Title(title),m_Window(nullptr)
{
	init();
	for (int i = 0; i < MAX_KEYS; i++)
		m_Keys[i] = false;
	for (int i = 0; i < MAX_BUTTONS; i++)
		m_Buttons[i] = false;
}

Window::~Window(){
	glfwDestroyWindow(m_Window);
}

void Window::update() const{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

bool Window::closed() const{
	return glfwWindowShouldClose(m_Window);
}

void Window::clear() const{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetFramebufferSizeCallback(m_Window, windowResized);
	glfwSetKeyCallback(m_Window, key_callback);
	glfwSetMouseButtonCallback(m_Window, mouse_callback);
	glfwSetCursorPosCallback(m_Window, cursor_pos_callback);


	gladLoadGLLoader(GLADloadproc(glfwGetProcAddress));

}

void windowResized(GLFWwindow* window,int width, int height) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	glfwGetFramebufferSize(win->GetWinPointer(), &win->m_Width, &win->m_Height);
	glViewport(0, 0, win->m_Width, win->m_Height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Keys[key] = action != GLFW_RELEASE;
}

void mouse_callback(GLFWwindow* window, int button, int action, int mods){
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Buttons[button] = action != GLFW_RELEASE;
}

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos){
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->mx = xpos;
	win->my = ypos;
}

void Window::getMousePosition(double& x, double& y) const {
	x = this->mx;
	y = this->my;
}

bool Window::isKeyPressed(unsigned int keycode) const {
	if (keycode >= MAX_KEYS)
		return false;
	else return m_Keys[keycode];
}

bool Window::isMousePressed(unsigned int button) const {
	if (button >= MAX_BUTTONS)
		return false;
	else return m_Buttons[button];
}










