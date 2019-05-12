#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "input/Input.h"

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

	GLuint vao, vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

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
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		
		//key mouse callback
		input.pressKeys(window);

		//swap buffers poll events
		window.update();
	
	}


	return 0;
}