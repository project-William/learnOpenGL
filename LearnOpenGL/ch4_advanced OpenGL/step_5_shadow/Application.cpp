#include "include/renderer/RenderCube.h"
#include "include/renderer/RenderBoard.h"
#include "Camera.h"

void ProcessInput();

int main()
{
	
	Window::Create(1200, 800, "cherno");
	auto window = Window::GetWindowInstance();

	std::shared_ptr<RenderCube> cube(new RenderCube("shader/cube.vert", "shader/cube.frag"));
	std::shared_ptr<RenderBoard> board(new RenderBoard("shader/cube.vert", "shader/cube.frag"));

	glEnable(GL_DEPTH_TEST);

	while (!window->Closed())
	{
		window->Clear();
		ProcessInput();

		cube->Draw(window->GetWindowPros(), window->GetWindowPros().m_Camera);
		board->Draw(window->GetWindowPros(), window->GetWindowPros().m_Camera);
		
		window->Update();
	}

	glfwTerminate();

	return 0;
}


void ProcessInput()
{
	auto window = Window::GetWindowInstance();
	if (glfwGetKey(window->GetWindowPros().m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window->GetWindowPros().m_Window, true);

	if (glfwGetKey(window->GetWindowPros().m_Window, GLFW_KEY_W) == GLFW_PRESS)
		window->GetWindowPros().m_Camera->ProcessKeyboard(FORWARD, window->GetDeltaTime());
	if (glfwGetKey(window->GetWindowPros().m_Window, GLFW_KEY_S) == GLFW_PRESS)
		window->GetWindowPros().m_Camera->ProcessKeyboard(BACKWARD, window->GetDeltaTime());
	if (glfwGetKey(window->GetWindowPros().m_Window, GLFW_KEY_A) == GLFW_PRESS)
		window->GetWindowPros().m_Camera->ProcessKeyboard(LEFT, window->GetDeltaTime());
	if (glfwGetKey(window->GetWindowPros().m_Window, GLFW_KEY_D) == GLFW_PRESS)
		window->GetWindowPros().m_Camera->ProcessKeyboard(RIGHT, window->GetDeltaTime());
}