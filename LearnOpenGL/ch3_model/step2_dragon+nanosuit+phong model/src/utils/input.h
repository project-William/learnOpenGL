#pragma once
#include "graphics/Window.h"

class Input {
public:

	Input() {}
	~Input() {}

	void pressKeys(Window& window);

};

void Input::pressKeys(Window& window) {
	if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(window.getWindow(), true);
	}

	if (window.isKeyPressed(GLFW_KEY_W)) {
		window.getCamera()->ProcessKeyboard(FORWARD, window.getDeltaTime());
	}

	if (window.isKeyPressed(GLFW_KEY_A)) {
		window.getCamera()->ProcessKeyboard(LEFT, window.getDeltaTime());
	}

	if (window.isKeyPressed(GLFW_KEY_S)) {
		window.getCamera()->ProcessKeyboard(BACKWARD, window.getDeltaTime());
	}

	if (window.isKeyPressed(GLFW_KEY_D)) {
		window.getCamera()->ProcessKeyboard(RIGHT, window.getDeltaTime());
	}
}