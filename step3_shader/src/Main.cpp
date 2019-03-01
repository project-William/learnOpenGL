#include "Window.h"	
#include "Renderer.h"

int main() {

	Window window("learn", 1200, 800);
	Renderer render;

	Shader myshader("res/shader.hlsl");

	float vertices[] = {
		 0.0f, 0.5f,0.0f,
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f
	};

	vertexBuffer vb(sizeof(vertices), vertices);
	vertexArray va;
	vertexLayout layout;
	layout.push<float>(3);
	va.addBuffer(vb, layout);

	while (!window.closed())
	{
		render.Clear();

		myshader.bind();
		va.bind();
		render.Draw(va, myshader, layout, vb);

		window.update();
	}

	glfwTerminate();
	return 0;
}



