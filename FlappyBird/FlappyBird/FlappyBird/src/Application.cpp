#include "Application.h"

Application::Application() {
	myWindow = new graphics::Window(1270, 800, "Flappy Bird");
	input = new utils::Input();
	render = new graphics::Render();
}


Application::~Application() {
	delete myWindow;
	delete input;
	delete render;
}


void Application::run() {	

	float time = 1000.0f;
	int frames = 0;
	while (!myWindow->closed()) {
		//process input
		input->processInput(*myWindow);
		
		//clear buffer
		myWindow->clear();
		//draw a rectangular
		render->render(*myWindow);
		render->update();

		//swapbuffer & events
		myWindow->udpate();
		frames++;
	}



}