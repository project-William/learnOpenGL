#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include "Camera.h"
#include <memory>

class Window {
private:
	GLFWwindow* m_Window;
	int m_Width;
	int m_Height;
	const char* m_Title;
	bool firstMouse = true;
	float last_x;
	float last_y;
	friend class Input;
public:
	std::shared_ptr<Camera> camera;
	Window(int width, int height, const char* title);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	inline int GetWidth()const { return m_Width; }
	inline int GetHeight()const { return m_Height; }
	GLFWwindow* getWindow()const { return m_Window; }
	void update()const;
	void clear()const;
	bool closed()const;
private:
	bool init();
	friend void windowResized(GLFWwindow* window, int width, int height);
	friend void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	friend void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};