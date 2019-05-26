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

	int index=0;
	 
	
	while (!myWindow->closed()) {
		//process input
		input->processInput(*myWindow);
		
		//clear buffer
		myWindow->clear();
		//draw a rectangular
		render->renderBackground();
		render->renderPipes();
		index++;
		render->renderBird(*myWindow);
		render->update();

		//swapbuffer & events
		myWindow->udpate();
	}



}