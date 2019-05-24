#include "Input.h"


namespace flappy {
	namespace utils {
		void Input::processInput(graphics::Window& window) {

			if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
				std::cout << "Key[ESC] pressed!" << std::endl;
				glfwSetWindowShouldClose(window.getWindow(), true);
			}

			if (window.isKeyPressed(GLFW_KEY_W)) {
				std::cout << "Key[W] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_A)) {
				std::cout << "Key[A] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_S)) {
				std::cout << "Key[S] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_D)) {
				std::cout << "Key[D] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_UP)) {
				std::cout << "Key[UP] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_DOWN)) {
				std::cout << "Key[DOWN] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_LEFT)) {
				std::cout << "Key[LEFT] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_RIGHT)) {
				std::cout << "Key[RIGHT] pressed!" << std::endl;
			}

			if (window.isKeyPressed(GLFW_KEY_SPACE)) {
				std::cout << "key[SPACE] pressed!" << std::endl;
			}
		}
	}
}