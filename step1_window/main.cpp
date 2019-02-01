#include "Window.h"	

int main() {
	Window window(1200, 800, "William");
	
	glClearColor(1.0f, 1.0f, 0.2f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.Closed())
	{
		window.ProcessInput();
		window.Clear();

		window.Update();
	}

	return 0;
}