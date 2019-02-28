#include "Window.h"	

int main() {

	Window window("learn", 1200, 800);
	Renderer render;
	while (!window.closed())
	{
		std::cout << window.GetWidth() << " " << window.GetHeight() << std::endl;
		render.clear();
		window.update();
	}

	glfwTerminate();
	return 0;
}



