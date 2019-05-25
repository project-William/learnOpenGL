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
	delete shader;
}


void Application::run() {

	float vertices[18] = {
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		-0.5f, 0.5f,0.0f,
		-0.5f, 0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		 0.5f, 0.5f,0.0f,
	};

	unsigned int vao, vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	shader->enableProgram();
	math::Vec3 vec(1.0f, 0.0f, 0.0f);
	shader->setVec3("color", vec);

	while (!myWindow->closed()) {
		//process input
		input->processInput(*myWindow);
		
		//clear buffer
		myWindow->clear();
		//draw a rectangular
		shader->enableProgram();
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		//swapbuffer & events
		myWindow->udpate();
	}



}