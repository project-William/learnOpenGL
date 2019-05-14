#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "input/Input.h"
#include "graphics/buffer/bufferLayout.h"

int main()
{
	Window window(800, 800, "william");
	Shader shader("res/Text.txt");
	Input input;

	float vertices[] = {
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		-0.5f, 0.5f,0.0f,
		-0.5f, 0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		 0.5f, 0.5f,0.0f
	};
	
	VertexBuffer vbo(sizeof(vertices),vertices);
	VertexArray vao;
	BufferLayout layout;
	layout.addBuffer(vao, vbo);


	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, -0.5f, 0.0f));

	glm::mat4 model1(1.0f);


	double xpos=0, ypos=0;
	glm::vec2 light_pos(xpos, ypos);

	while (!window.close())
	{
		//clear buffer
		window.clear();
		glClearColor(0.0f, 0.0f, 0.05f, 0.5f);
		//render light
		window.getMousePos(xpos,ypos);
		
		light_pos.x = (xpos - window.getWidth() / 2) / window.getWidth() * 2;
		light_pos.y = -(ypos - window.getHeight() / 2) / window.getHeight() * 2;
		std::cout << light_pos.x << " " << light_pos.y << std::endl;

		shader.SetVec2("light_pos", light_pos);
		
		//render a rectangle
		shader.bind();
		vao.bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		//key mouse callback
		input.pressKeys(window);

		//swap buffers poll events
		window.update();
	
	}


	return 0;
}