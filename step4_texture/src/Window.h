#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Window
{
private:
	int m_Width, m_Height;
	const char* m_Title;
public:
	GLFWwindow* m_Window;
	Window(const char* title,int width,int height);
	~Window();

	bool closed()const;
	void update()const;
	friend void processInput(GLFWwindow* window);
private:
	bool init();
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

