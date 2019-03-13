#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Window {
private:
	const char* m_Title;
	int m_Width;
	int m_Height;
	GLFWwindow* m_Window;

	bool m_Keys[MAX_KEYS];
	bool m_Buttons[MAX_BUTTONS];
	double mx, my;

	
public:

	Window(unsigned int width,unsigned int height,const char* title);
	~Window();
	void update() const;
	bool closed() const;
	void clear() const;
	inline const int GetWidth()const { return m_Width; }
	inline const int GetHeight()const { return m_Height; }
	inline GLFWwindow* GetWinPointer() const { return m_Window; }
	void getMousePosition(double& x, double& y) const;
	bool isKeyPressed(unsigned int keycode) const;
	bool isMousePressed(unsigned int button) const;
private:
	void init();
	friend void windowResized(GLFWwindow* window, int width, int height);
	friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);


};