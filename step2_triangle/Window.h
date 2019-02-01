#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, const char*title);
	void Update();
	bool Closed() const;
	void Clear();
	void ProcessInput() const;
	~Window();
private:
	void WindowResized();
	bool Init();
private:
	int m_Width, m_Height;
	const char*m_Title;
	GLFWwindow* m_window;
};

