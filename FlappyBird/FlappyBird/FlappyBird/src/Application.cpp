#include "Application.h"

Application::Application() {
	myWindow = new graphics::Window(1270, 800, "Flappy Bird");
	input = new utils::Input();
	const std::string vfile = "src/shader/basicVertex.vert";
	const std::string ffile = "src/shader/basicFragment.frag";

	shader = new graphics::Shader(vfile,ffile);
}


Application::~Application() {
	delete myWindow;
	delete input;
}


void Application::run() {



	while (!myWindow->closed()) {
		//process input
		input->processInput(*myWindow);
		
		//clear buffer
		myWindow->clear();


		//swapbuffer & events
		myWindow->udpate();
	}



}