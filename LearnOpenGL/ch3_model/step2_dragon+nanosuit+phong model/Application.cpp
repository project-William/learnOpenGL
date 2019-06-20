#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "utils/input.h"
#include "graphics/Model.h"
#include <vector>
int main(int argc, char** argv)
{
	Window window(1200, 800, "william");
	Shader shader("src/shader/dragon.vert","src/shader/dragon.frag");
	Shader light("src/shader/nanosuit.vert", "src/shader/nanosuit.frag");
	Input input;

	std::string exepath = argv[0];
	
	Model mymodel(exepath.substr(0,exepath.find_last_of('\\'))+"\\model\\dragon.obj");
	Model lightm(exepath.substr(0, exepath.find_last_of('\\')) + "\\model2\\nanosuit.obj");

	glEnable(GL_DEPTH_TEST);

	//model matrix view matrix projection matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	projection = glm::perspective(glm::radians(45.0f), (float)window.getWidth() / window.getHeight(), 0.1f, 100.0f);
	
	glm::vec3 lightPos(1.0f, 6.0f, 1.5f);


	while (!window.close())
	{
		//get frame time
		window.frameTime();
		
		//key mouse callback
		input.pressKeys(window);

		//clear buffer
		window.clear();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		//render a dragon

		shader.bind();

		view = window.getCamera()->getViewMatrix();
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		shader.setVec3("lightPos", lightPos);
		shader.setVec3("viewPos", window.getCamera()->Position);
	

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f)); 
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	
		shader.setMat4("model", model);
		mymodel.Draw(shader);
		
		//nanosuit
		light.bind();
		glm::mat4 model1 = glm::mat4(1.0f);
		model1 = glm::translate(model1, glm::vec3(2.0f,-2.0f,0.0f));
		model1 = glm::scale(model1, glm::vec3(0.2f, 0.2f, 0.2f));
		light.setMat4("model", model1);
		light.setMat4("view", view);
		light.setMat4("projection", projection);
		light.setVec3("lightPos", lightPos);
		light.setVec3("viewPos", window.getCamera()->Position);

		lightm.Draw(light);
		
		//swap buffers poll events
		window.update();
	
	}


	return 0;
}