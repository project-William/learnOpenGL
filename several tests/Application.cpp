#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "input/Input.h"
#include "graphics/buffer/bufferLayout.h"
#include "graphics/render.h"
#include <vector>
int main()
{
	Window window(800, 800, "william");
	Shader shader("res/basicVertexShader.vert","res/basicFragmentShader.frag");
	Input input;
	Render render;

	std::vector<float> vertices = {
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		-0.5f, 0.5f,0.0f,
		-0.5f, 0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		 0.5f, 0.5f,0.0f
	};
	
	VertexBuffer vbo(vertices.size(), &vertices[0], 3);
	VertexArray vao;
	BufferLayout layout;
	layout.addBuffer(vao, vbo, 0);

	//model matrix view matrix projection matrix
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	model = glm::rotate(model, glm::radians(55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)window.getWidth() / window.getHeight(), 0.1f, 100.0f);

	while (!window.close())
	{
		//clear buffer
		window.clear();
		glClearColor(0.0f, 0.0f, 0.05f, 0.5f);

		//render a rectangle
		shader.bind();

		shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		
		render.draw(vao);




		//key mouse callback
		input.pressKeys(window);

		//swap buffers poll events
		window.update();
	
	}


	return 0;
}