#define STB_IMAGE_IMPLEMENTATION
#include "src/vendor/stb_image.h"
#include "src/Window.h"
#include "src/Shader.h"
#include "src/Render.h"
#include "src/VertexBuffer.h"
#include "src/VertexArray.h"
#include "src/Texture.h"
#include "src/VertexLayout.h"
#include "src/FrameBuffer.h"
#include "src/Input.h"
#include "res/vertexData.h"
#include "src/Coordinate.h"
#include <math.h>
#include <memory>


int main() {

	Window window(1980, 1080, "willaim");
	Render render;
	//cube with texture
	Shader cubeShader("res/cube.shader");
	Texture2D tex0("res/texture2D/container2.png");
	VertexBuffer vb;
	vb.bind(0);
	vb.push(sizeof(vertices), vertices);
	VertexArray va;
	va.bind(0);
	VertexLayout cubeLayout(36, sizeof(vertices));
	//set vertex attrib pointer and enable the pointer 
	cubeLayout.push<float>(0, 3);
	cubeLayout.push<float>(1, 3);
	cubeLayout.push<float>(2, 2);
	va.addBuffer(cubeLayout);
	va.bind(0);
	cubeShader.SetInt("material.diffuse", 0);

	//light cube
	Shader lightShader("res/light.shader");
	vb.bind(1);
	vb.push(sizeof(light), light);
	va.bind(1);
	VertexLayout lightLayout(36, sizeof(light));
	lightLayout.push<float>(0, 3);
	va.addBuffer(lightLayout);
	va.bind(1);
	//skybox
	Shader skyboxShader("res/cubeMap.shader");
	Texture3D skyboxTex(
		"res/texture3D/skybox/right.jpg",
		"res/texture3D/skybox/left.jpg",
		"res/texture3D/skybox/bottom.jpg",
		"res/texture3D/skybox/top.jpg",
		"res/texture3D/skybox/front.jpg",
		"res/texture3D/skybox/back.jpg"
	);
	vb.bind(2);
	vb.push(sizeof(skyboxVertices), skyboxVertices);
	va.bind(2);
	VertexLayout skyboxLayout(36, sizeof(skyboxVertices));
	skyboxLayout.push<float>(0, 3);
	va.addBuffer(skyboxLayout);
	va.bind(2);
	skyboxShader.bind();
	skyboxShader.SetInt("skybox", 0);
	
	//input mode
	Input input;
	//light position
	glm::vec3 lightPos(-200.0f, 200.0f, -300.0f);

	while (!window.closed())
	{
		glEnable(GL_DEPTH_TEST);
		//clear color
		render.clear(0.1f, 0.1f, 0.1f, 1.0f);
		//key callback
		input.processInput(window.getWindow());
		//cube of phong reflection model
		cubeShader.bind();
		tex0.bind(0);
		va.bind(0);
		Coordinate objCoord(cubeShader, window, "cubeShader");
		for (unsigned int i = 0; i < 10; i++)
		{
			render.PhongReflection(lightPos, window, cubeShader);
			objCoord.changePos(cubePositions,i);
			render.draw(cubeLayout);
		}
		va.unbind();
		//skybox
		glDepthFunc(GL_LEQUAL);
		skyboxShader.bind();
		Coordinate skyboxCoord(skyboxShader, window, "cubeMap");
		va.bind(2);		
		skyboxTex.bind();
		render.draw(skyboxLayout);
		va.unbind();
		glDepthFunc(GL_LESS);
		//swap buffers and poll events
		window.update();
	}
	glfwTerminate();
	return 0;
}