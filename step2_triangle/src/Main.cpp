#include "Window.h"	
#include "Renderer.h"
#include "Shader.h"

int main() {

	Window window("learn", 1200, 800);
	Renderer render;

	Shader myshader("res/shader.hlsl");

	float vertices[] = {
		 0.0f, 0.5f,0.0f,
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f
	};

	unsigned int VAO, VBO;
	GLCall(glGenBuffers(1, &VBO));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));
		 
	GLCall(glGenVertexArrays(1, &VAO));
	GLCall(glBindVertexArray(VAO));
		 
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0));
	GLCall(glEnableVertexAttribArray(0));

	while (!window.closed())
	{
		render.Clear();

		myshader.bind();
		GLCall(glBindVertexArray(VAO));
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));

		window.update();
	}

	glfwTerminate();
	return 0;
}



