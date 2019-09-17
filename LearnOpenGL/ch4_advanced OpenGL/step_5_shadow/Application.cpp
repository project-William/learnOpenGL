#include "include/renderer/RenderCube.h"
#include "include/renderer/RenderBoard.h"


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

		cube->Draw(window->GetWindowPros());
		board->Draw(window->GetWindowPros());
		
		window->Update();
	}

	glfwTerminate();

	return 0;
}