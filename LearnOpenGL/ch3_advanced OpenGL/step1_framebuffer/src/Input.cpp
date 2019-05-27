#include "Input.h"


Input::Input()
{
	
}

Input::~Input()
{
}

void Input::processInput(GLFWwindow* window)
{
	float speed = 0.1f;
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	if (glfwGetKey(win->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(win->getWindow(), GL_TRUE);
		std::cout << "pressed!" << std::endl;
	}

	if (glfwGetKey(win->getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		win->camera->processKeyboard(FOREWARD, deltaTime);
		std::cout << "pressed!" << std::endl;
	}

	if (glfwGetKey(win->getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		win->camera->processKeyboard(BACKWARD, deltaTime);
		std::cout << "pressed!" << std::endl;
	}

	if (glfwGetKey(win->getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		win->camera->processKeyboard(LEFT, deltaTime);
		std::cout << "pressed!" << std::endl;
	}

	if (glfwGetKey(win->getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		win->camera->processKeyboard(RIGHT, deltaTime);
		std::cout << "pressed!" << std::endl;
	}
		
}
