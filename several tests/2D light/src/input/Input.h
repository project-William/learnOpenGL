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

}