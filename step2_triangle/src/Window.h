#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(const char* title,int width,int height);
	bool closed()const;
	void update()const;
	bool init();
	~Window();
	
	inline const int& GetWidth()const { return m_Width; }
	inline const int& GetHeight()const { return m_Height; }

public:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;
};

