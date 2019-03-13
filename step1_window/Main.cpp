#include "src/Window.h"


int main()
{
	Window win(1200, 720, "william");

	while (!win.closed())
	{
		win.clear();
		double x, y;
		win.getMousePosition(x, y);
		std::cout << x << " " << y <<std::endl;

		win.update();
	}

	glfwTerminate();
	return 0;
}