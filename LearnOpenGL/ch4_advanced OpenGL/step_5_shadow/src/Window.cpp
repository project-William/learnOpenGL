#include "Window.h"

std::shared_ptr<Window> Window::m_Instance = nullptr;

void Window::Create(int width, int height, const char* title)
{
	m_Instance = std::shared_ptr<Window>(new Window(width, height, title));
}

void Window::Update()
{
	glfwSwapBuffers(m_WinPros.m_Window);
	glfwPollEvents();
}

void Window::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}


bool Window::Closed()
{
	return glfwWindowShouldClose(m_WinPros.m_Window) == 1;
}

bool Window::Init(int width, int height, const char* title)
{
	m_WinPros.m_Height = height;
	m_WinPros.m_Width = width;
	m_WinPros.m_Title = title;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_WinPros.m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!m_WinPros.m_Window)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_WinPros.m_Window);
	glfwSetWindowUserPointer(m_WinPros.m_Window, &m_WinPros);
	glfwSetFramebufferSizeCallback(m_WinPros.m_Window, [](GLFWwindow* window, int width, int height)
	{
		auto& winPros = *static_cast<WindowPros*>(glfwGetWindowUserPointer(window));
		winPros.m_Height = height;
		winPros.m_Width = width;
		glViewport(0, 0, width, height);
	});


	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
	{
		std::cout << "Failed to load opengl functions" << std::endl;
		glfwTerminate();
		return false;
	}

	return true;

}

Window::Window(int width, int height, const char* title)
{
	if (!Init(width, height, title))
	{
		std::cout << "Failed to init window!" << std::endl;
	}
	else
	{
		std::cout << "Success" << std::endl;
	}
}