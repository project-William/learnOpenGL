#include "Window.h"

namespace flappy {
	namespace graphics {
		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_BUTTONS];


		void windowResized(GLFWwindow* window, int height, int width);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
		void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
		void curorPos_callback(GLFWwindow* window, double xpos, double ypos);


		Window::Window(int width, int height, const char* title)
			:m_Width(width), m_Height(height), m_Title(title),m_PosX(0),m_PosY(0)
		{
			if (!init())
				std::cout << "Unable to initialize the Window!" << std::endl;
			else std::cout << "Success!" << std::endl;
		}

		bool Window::init() {

			if (!glfwInit()) {
				std::cout << "Failed to initialize the GLFW!" << std::endl;
				return false;
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
			if (!m_Window) {
				std::cout << "Failed to create the window!" << std::endl;
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, windowResized);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetCursorPosCallback(m_Window, curorPos_callback);


			if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
				std::cout << "Failed to initialize the GLAD!" << std::endl;
				return false;
			}


			return true;
		}

		bool Window::isKeyPressed(unsigned int keycode) {

			return keycode >= MAX_KEYS
				? false
				: m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) {
			
			return button >= MAX_BUTTONS
				? false
				: m_MouseButtons[button];
		}

		void Window::udpate() {
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.4f, 0.3f, 1.0f, 1.0f);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}
		//friend functions: windowResized(),key_callback(),mouseButton_callback(),cursorPos_callback()

		void windowResized(GLFWwindow* window, int height, int width) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			glfwGetFramebufferSize(win->m_Window, &win->m_Width, &win->m_Height);
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouseButton_callback(GLFWwindow* window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void curorPos_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_PosX = xpos;
			win->m_PosY = ypos;
		}


	}
}
