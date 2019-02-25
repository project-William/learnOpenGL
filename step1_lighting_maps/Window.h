#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Camera.h"
class Window {
public:
	int m_width, m_height;
	const char* m_title;
	GLFWwindow* m_window;
	Camera camera;

	float last_x = m_width / 2.0f;
	float last_y = m_height / 2.0f;
	bool firstMouse = true;

	//timing
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

public:
	Window(){}
	Window(const char* title, int width, int height);
	void update()const;
	bool closed()const;
	void clear()const;
	void processInput(GLFWwindow* window);

	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	friend void mouse_callback(GLFWwindow* window, double xpos, double xyos);
	friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	
};
