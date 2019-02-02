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
	//triangle's new color (uniform)
	glm::vec4 newcolor = glm::vec4(1.0f, 0.1f, 0.0f, 1.0f);

	while (!window.Closed())
	{
		std::cout << "width:" << window.GetWidth() << " " << "height:" << window.GetHeight() << std::endl;


		window.ProcessInput();
		window.Clear();


		myshader.Use();
		myshader.ColorChange("ourColor");

		//first triangle
		myshader.Draw(0);
		//second triangle
		myshader.Draw(1);


		window.Update();
	}

	return 0;
}