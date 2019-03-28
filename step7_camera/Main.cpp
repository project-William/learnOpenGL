#include "src/Window.h"
#include "src/Shader.h"
#include "src/Render.h"
#include <math.h>
#include "src/VertexBuffer.h"
#include "src/VertexArray.h"
#include "src/Texture.h"
#include "src/VertexLayout.h"

#include "src/Input.h"
#include "res/vertexData.h"
#include "src/Coordinate.h"



int main() {

	Window window(1200, 800, "willaim");
	Render render;
	//cube with texture
	Shader cubeShader("res/cube.shader");
	Texture tex0("res/container2.png");
	VertexBuffer vb;
	vb.bind(0);
	vb.push(sizeof(vertices), vertices);
	VertexArray va;
	va.bind(0);
	VertexLayout cubeLayout(36, sizeof(vertices));
	cubeLayout.push<float>(0, 3);
	cubeLayout.push<float>(1, 2);
	va.addBuffer(cubeLayout);
	va.bind(0);
	cubeShader.SetInt("texture0", 0);

	//light cube
	Shader lightShader("res/light.shader");
	vb.bind(1);
	vb.push(sizeof(light), light);
	va.bind(1);
	VertexLayout lightLayout(36, sizeof(light));
	lightLayout.push<float>(0, 3);
	va.addBuffer(lightLayout);
	va.bind(1);
	//input mode
	Input input;
	

	glEnable(GL_DEPTH_TEST);
	while (!window.closed())
	{
		//clear
		render.clear(0.1f, 0.1f, 0.1f, 1.0f);
		//key callback
		input.processInput(window.getWindow());
		//draw cube with texture
		cubeShader.bind();
		Coordinate objCoord(cubeShader, window);
		tex0.bind(0);
		va.bind(0);
		render.draw(cubeLayout);
		//draw light 
		lightShader.bind();
		Coordinate lightCoord(lightShader, window);
		lightCoord.resetMVP(glm::vec3(1.2f, 1.0f, 0.6f), glm::vec3(0.4f));
		va.bind(1);
		render.draw(lightLayout);
		//swap buffers and poll events
		window.update();
	}


	glfwTerminate();
	return 0;
}