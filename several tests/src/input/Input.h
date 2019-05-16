#pragma once
#include "graphics/Window.h"

class Input {
public:
	Input(){}
	~Input(){}

	void pressKeys(Window& window);

};

void Input::pressKeys(Window& window) {
	if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
		std::cout << "Key[ESC] pressed!" << std::endl;
		glfwSetWindowShouldClose(window.getWindow(), true);
	}

	if (window.isKeyPressed(GLFW_KEY_W)) {
		std::cout << "Key[W] pressed!" << std::endl;

	}

	if (window.isKeyPressed(GLFW_KEY_A)) {
		std::cout << "Key[A] pressed!" << std::endl;

	}

	if (window.isKeyPressed(GLFW_KEY_S)) {
		std::cout << "Key[S] pressed!" << std::endl;

	}

	if (window.isKeyPressed(GLFW_KEY_D)) {
		std::cout << "Key[D] pressed!" << std::endl;

	}


}