#include "Window.h"	

int main() {

	Window window("learn", 1200, 800);
	Renderer render;
	while (!window.closed())
	{
		render.clear();
		window.update();
	}

	glfwTerminate();
	return 0;
}



