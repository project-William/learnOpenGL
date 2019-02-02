#include "Window.h"	
#include "Shader.h"
#include "vertex_data.h"
#include "Texture.h"

int main() {
	Window window(1200, 800, "William");
	//window background color
	glClearColor(1.0f, 1.0f, 0.2f, 1.0f);
	
	std::cout << glGetString(GL_VERSION) << std::endl;

	Shader myshader("vs.vert", "fs.frag");
	myshader.VaoVboEbo(1);
	myshader.RectangularSetup(sizeof(vertices),vertices,sizeof(indices),indices);


	Texture mytexture1(0, "container.jpg", GL_RGB, GL_RGB);
	Texture mytexture2(1, "awesomeface.png", GL_RGBA, GL_RGBA);

	myshader.Use();
	myshader.SetInt("texture1", 0);
	myshader.SetInt("texture2", 1);

	while (!window.Closed())
	{
		//std::cout << "width:" << window.GetWidth() << " " << "height:" << window.GetHeight() << std::endl;

		window.ProcessInput();
		window.Clear();

		//rectangular
		myshader.Use();
		myshader.Draw(0);
		myshader.ColorChange("newColor");

		//textures
		mytexture2.UseTexture(GL_TEXTURE1, 1);
		mytexture1.UseTexture(GL_TEXTURE0, 0);

		

		window.Update();
	}

	return 0;
}