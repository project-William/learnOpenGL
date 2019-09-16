#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <iostream>

struct WindowPros
{
	GLFWwindow* m_Window;
	int m_Width, m_Height;;
	const char* m_Title;
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
private:
	bool Init(int width, int height, const char* title);
	explicit Window(int width, int height, const char* title);
	
	WindowPros m_WinPros;
	static std::shared_ptr<Window> m_Instance;
};