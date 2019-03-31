#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace GLfw {
	class Window {
	private:
		int m_Width;
		int m_Height;
		const char* m_Title;
		GLFWwindow* m_Window;
		static Window* instance;
	private:
		Window();
		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;

		bool closed()const;
		void update()const;
		void loadGL()const;
		void createWindow();
	public:
		static Window* GetInstance();
		inline int GetWidth()const { return m_Width; }
		inline int GetHeight()const { return m_Height; }
		void Init(int width, int height, const char* title);
		void Run()const;
		void Terminate()const;
	};
}