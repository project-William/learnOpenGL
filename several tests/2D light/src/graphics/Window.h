#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define MAX_KEYS 1024
#define MAX_BUTTONS 32




class Window {
private:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;

	double m_x, m_y;

	static bool m_MouseButtons[MAX_BUTTONS];
	static bool m_Keys[MAX_KEYS];

public:
	Window(){}
	~Window(){}
	Window(int width, int height, const char* title);
	void clear()const;
	bool close()const;
	void update();

	inline GLFWwindow* getWindow()const { return m_Window; }
	inline int getWidth()const { return m_Width; }
	inline int getHeight()const { return m_Height; }
	bool isKeyPressed(unsigned int keycode);
	bool isMouseButtonPressed(unsigned int button);


	inline void getMousePos(double& x, double& y)const { x = m_x, y = m_y; }
	inline void showMousePos()const { std::cout << m_x << " " << m_y << std::endl; }

	friend static void windowResized(GLFWwindow* window,int width,int height);
	friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend static void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void curorPos_callback(GLFWwindow* window, double xpos, double ypos);
private:
	bool init();

};