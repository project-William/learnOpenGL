#include "Window.h"
#include "Shader.h"
#include "vertex_data.h"
#include "Texture.h"
#include "Coordinate.h"



int main() {

	Window window(1200, 800, "william");
	Shader myshader("vs.vert", "fs.frag");

	glClearColor(1.0f, 1.0f, 0.2f, 1.0f);
	
	Texture texture1(0,"container.jpg",GL_RGB,GL_RGB);
	Texture texture2(1, "hh.png", GL_RGBA, GL_RGBA);

	myshader.VaosVbos();
	myshader.RectangluarSetup(0,sizeof(vertices),vertices);


	myshader.UseProgram();
	myshader.SetInt("myTexture0", 0);
	myshader.SetInt("myTexture1", 1);

	

	glEnable(GL_DEPTH_TEST);

	while (!window.Closed())
	{
		window.Clear();
		window.ProcessInput();

		//textures
		texture1.UseTexture(GL_TEXTURE0,0);
		texture2.UseTexture(GL_TEXTURE1,1);


		//setup rectangular
		myshader.UseProgram();
		myshader.Draw();

		//box
		Coordinate coord(window.m_Width, window.m_Height);
		myshader.SetMat4("model", coord.model);
		myshader.SetMat4("view", coord.view);
		myshader.SetMat4("projection", coord.projection);

		

		window.Update();
	}


	glfwTerminate();
	return 0;
}