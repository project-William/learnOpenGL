#include "Window.h"
#include "Renderer.h"

int main() {
	{
		Window window("william", 1200, 800);
		Renderer render;
		

		while (!window.closed()) {

			render.clear(0.2f, 0.4f, 1.0f, 1.0f);
			window.update();
		}
	}
	glfwTerminate();

	return 0;
}
