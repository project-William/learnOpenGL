#include "Window.h"
#include "Shader.h"
#include "vertex_data.h"
#include "Texture.h"
#include "Transformation.h"



int main() {

	Window window(1200, 800, "william");
	Shader myshader("vs.vert", "fs.frag");
	Transformation transform;

	glClearColor(1.0f, 1.0f, 0.2f, 1.0f);
	
	Texture texture1(0,"container.jpg",GL_RGB,GL_RGB);
	Texture texture2(1, "hh.png", GL_RGBA, GL_RGBA);

	myshader.VaosVbos();
	myshader.RectangluarSetup(0,sizeof(vertices),vertices);


	myshader.UseProgram();
	myshader.SetInt("myTexture0", 0);
	myshader.SetInt("myTexture1", 1);

	


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


		//transformation
		transform.Translate(-0.0f, 0.0f, 0.0f);
		transform.Rotate(0.5f, 0.0f, 0.0f, 1.0f);
		transform.Scale(1.0001f, 1.0001f, 0.0f);
		myshader.SetMat4("trans", transform.trans);

		window.Update();
	}


	glfwTerminate();
	return 0;
}