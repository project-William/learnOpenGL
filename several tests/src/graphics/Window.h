#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "utils/camera.h"
#include <iostream>
#define MAX_KEYS 1024
#define MAX_BUTTONS 32



class Window {
private:
	int m_Width, m_Height;
	const char* m_Title;
	GLFWwindow* m_Window;

	Camera* m_Camera;

	double m_x, m_y;

	static bool m_MouseButtons[MAX_BUTTONS];
	static bool m_Keys[MAX_KEYS];

	float m_DeltaTime = 0.0f;
	float m_CurrentFrame, m_LastFrame;
	
	bool firstMouse = true;
	float lastX= getWidth() /2.0f;
	float lastY= getHeight() /2.0f;

public:
	Window(){}
	~Window() { delete m_Camera; }
	Window(int width, int height, const char* title);
	void clear()const;
	bool close()const;
	void update();

	inline GLFWwindow* getWindow()const { return m_Window; }
	inline int getWidth()const { return m_Width; }
	inline int getHeight()const { return m_Height; }
	inline float getDeltaTime()const { return m_DeltaTime; }
	inline Camera* getCamera()const { return m_Camera; }
	bool isKeyPressed(unsigned int keycode);
	bool isMouseButtonPressed(unsigned int button);

	void frameTime();

	

	friend void windowResized(GLFWwindow* window,int width,int height);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
	friend void curorPos_callback(GLFWwindow* window, double xpos, double ypos);
private:
	bool init();

};