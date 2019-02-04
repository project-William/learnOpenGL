#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const char*title);
	bool Closed() const;
	void WindowResized();
	void Update();
	void ProcessInput();
	void Clear() const;
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	~Window();
private:
	bool Init();
private:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_window;

};
