#include "src/Application.h"
using namespace flappy::math;

int main() {
	Application* app = new Application();
	app->run();
	delete app;

	return 0;
}