#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "utils/input.h"
//#include "graphics/buffer/bufferLayout.h"
//#include "graphics/render.h"
#include "graphics/Mesh.h"

//#include "graphics/texture/texture.h"
#include <vector>
int main()
{
	Window window(800, 800, "william");
	Shader shader("res/basicVertexShader.vert","res/basicFragmentShader.frag");
	Input input;
	//Render render;
	

	std::vector<Vertex> m_Vertices = {
		{{-0.5f,-0.5f,0.0f}},//{0.0f,0.0f}},
		{{ 0.5f,-0.5f,0.0f}},//{1.0f,0.0f}},
		{{-0.5f, 0.5f,0.0f}},//{0.0f,1.0f}},
		{{-0.5f, 0.5f,0.0f}},//{0.0f,1.0f}},
		{{ 0.5f,-0.5f,0.0f}},//{1.0f,0.0f}},
		{{ 0.5f, 0.5f,0.0f}},//{1.0f,1.0f}}
	};


	std::cout << sizeof(Vertex) << std::endl;
	
	Mesh mesh(m_Vertices);


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
		glClearColor(0.1f, 0.4f, 0.1f, 1.0f);

		//render a rectangle
		//texture1.useTexture(0);
		view = window.getCamera()->getViewMatrix();
		shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		shader.bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		//render.draw(vao);

		//swap buffers poll events
		window.update();
	
	}


	return 0;
}