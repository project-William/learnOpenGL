#include "Window.h"	
#include "Shader.h"
#include "vertex_data.h"
int main() {
	Window window(1200, 800, "William");
	
	glClearColor(1.0f, 1.0f, 0.2f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	Shader myshader("vs.vert", "fs.frag");
	myshader.VaosAndVbos(2);
	//first triangle setup
	myshader.TriangleSetup(0, sizeof(firstTriangle), firstTriangle);
	//second triangle setup
	myshader.TriangleSetup(1, sizeof(secondTriangle), secondTriangle);

	while (!window.Closed())
	{
		window.ProcessInput();
		window.Clear();


		myshader.Use();

		//first triangle
		myshader.Draw(0);
		//second triangle
		myshader.Draw(1);


		window.Update();
	}

	return 0;
}