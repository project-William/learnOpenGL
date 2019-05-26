#include "Input.h"
#include <time.h>

namespace flappy {
	namespace utils {
		void Input::processInput(graphics::Window& window) {

			if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
				std::cout << "Key[ESC] pressed!" << std::endl;
				glfwSetWindowShouldClose(window.getWindow(), true);
			}
		}
	}
}