#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <iostream>
#include "Camera.h"

struct WindowPros
{
	GLFWwindow* m_Window;
	int m_Width, m_Height;;
	const char* m_Title;
	float lastX;
	float lastY;
	bool firstMouse = true;
	
	std::shared_ptr<Camera> m_Camera;

	WindowPros()
		:m_Camera(std::shared_ptr<Camera>(new Camera(glm::vec3((0.0f, 0.0f, 0.0f)))))
	{ 
	
	}

	~WindowPros()
	{
	
	}
};


class Window
{
public:
	static void Create(int width, int height, const char* title);
	void Update();
	void Clear();
	bool Closed();

	inline int GetWinHeight()const { return m_WinPros.m_Height; }
	inline int GetWinWidth()const { return m_WinPros.m_Width; }

	static inline std::shared_ptr<Window>& GetWindowInstance() { return m_Instance; }
	inline WindowPros& GetWindowPros() { return m_WinPros; }
	
	const float GetDeltaTime()const { return m_DeltaTime; }

private:
	bool Init(int width, int height, const char* title);
	explicit Window(int width, int height, const char* title);
	
	WindowPros m_WinPros;
	static std::shared_ptr<Window> m_Instance;

	const float m_DeltaTime = 0.05f;	
	float lastFrame = 0.0f;
	


};