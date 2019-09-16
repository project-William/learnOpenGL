#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "include/Window.h"
#include "include/Shader.h"
#include "include/renderer/VAOVBO/VertexArray.h"
#include "include/renderer/VAOVBO/VertexBuffer.h"


int main()
{
	
	Window::Create(1200, 800, "cherno");
	auto window = Window::GetWindowInstance();

	float vertices[] =
	{
		0.0f,0.5f,0.0f,
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
	};

	
	Shader shader("shader/cube.vert", "shader/cube.frag");

	VertexBuffer vb(sizeof(vertices), vertices);
	VertexArray va;
	va.AttribPointer(0, 3, 12, 0);


	while (!window->Closed())
	{
		window->Clear();

		va.Bind();
		shader.UseProgram();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		window->Update();
	}

	glfwTerminate();

	return 0;
}