#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "utils/input.h"
#include "graphics/Model.h"
#include <vector>
int main(int argc, char** argv)
{
	Window window(1200, 800, "william");
	Shader shader("src/shader/basicVertexShader.vert","src/shader/basicFragmentShader.frag");
	Input input;

	std::string exepath = argv[0];
	
	Model mymodel(exepath.substr(0,exepath.find_last_of('\\'))+"\\model\\nanosuit.obj");
	glEnable(GL_DEPTH_TEST);

	//model matrix view matrix projection matrix
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	model = glm::rotate(model, glm::radians(55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)window.getWidth() / window.getHeight(), 0.1f, 100.0f);


	while (!window.close())
	{
		//get frame time
		window.frameTime();
		
		//key mouse callback
		input.pressKeys(window);

		//clear buffer
		window.clear();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		//render a rectangle
		shader.bind();

		view = window.getCamera()->getViewMatrix();
		shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); 
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	
		shader.setMat4("model", model);
		mymodel.Draw(shader);

		//swap buffers poll events
		window.update();
	
	}


	return 0;
}