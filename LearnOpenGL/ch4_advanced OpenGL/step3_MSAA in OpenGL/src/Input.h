#pragma once
#include "Window.h"
#include <iostream>

class Input {
private:
	float deltaTime = 0.2f;
public:
	Input();
	~Input();
	void processInput(GLFWwindow* window);
};

 