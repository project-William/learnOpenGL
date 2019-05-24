#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

const int MAX_BUTTONS = 32;
const int MAX_KEYS = 1024;


namespace flappy {
	namespace graphics {

		class Window {
		private:
			int m_Width, m_Height;
			const char* m_Title;
			GLFWwindow* m_Window;
			//keys and buttons
			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			//mouse position
			int m_PosX;
			int m_PosY;

		public:
			Window() :m_Width(0), m_Height(0), m_Window(nullptr), m_Title("NULL") {}
			Window(int width, int height, const char* title);
			~Window() {}
			Window(const Window& other) = delete;
			Window& operator=(const Window& other) = delete;

			inline GLFWwindow* getWindow()const { return m_Window; };
			inline int getWidth()const { return m_Width; }
			inline int getHeight()const { return m_Height; }

			bool isKeyPressed(unsigned int keycode);
			bool isMouseButtonPressed(unsigned int Button);




			void udpate();
			void clear()const;
			bool closed()const;

		private:

			friend void windowResized(GLFWwindow* window, int height, int width);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
			friend void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
			friend void curorPos_callback(GLFWwindow* window, double xpos, double ypos);




			bool init();
		};
	}
}

