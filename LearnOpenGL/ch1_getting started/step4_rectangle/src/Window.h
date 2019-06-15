#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;
	float m_Color[4];
public:
	Window(int width, int height, const char* title);
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	~Window(){}
	inline GLFWwindow* getWindow()const { return m_Window; }
	inline float* getColorArray() { return m_Color; }
	bool close()const;
	void clear();
	void bufferUpdate()const;
private:
	bool init();
	friend void windowResized(GLFWwindow* window, int width, int height);
};