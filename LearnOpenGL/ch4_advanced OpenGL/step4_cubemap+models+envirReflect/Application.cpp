#include <iostream>
#include "graphics/Window.h"
#include "graphics/Shader.h"
#include "utils/input.h"
#include "graphics/Model.h"
#include "graphics/Skybox.h"

#include <vector>

unsigned int loadTexture(std::vector<std::string>& texture) {
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	int width, height, channels;

	for (int i = 0; i < texture.size(); i++) {
		unsigned char* data;
		data = stbi_load(texture[i].c_str(), &width, &height, &channels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else {
			std::cout << "failed to load skybox!" << std::endl;
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}


int main(int argc, char** argv)
{
	Window window(1200, 800, "william");
	Shader shader("src/shader/dragon.vert", "src/shader/dragon.frag");
	Shader nanosuitshader("src/shader/nanosuit.vert", "src/shader/nanosuit.frag");
	Shader skyboxshader("src/shader/skybox.vert", "src/shader/skybox.frag");
	Input input;

	Skybox skybox;

	std::vector<std::string> tex_faces = {
		"res/mp_impaler/impaler-point_ft.tga",
		"res/mp_impaler/impaler-point_bk.tga",
		"res/mp_impaler/impaler-point_up.tga",
		"res/mp_impaler/impaler-point_dn.tga",
		"res/mp_impaler/impaler-point_rt.tga",
		"res/mp_impaler/impaler-point_lf.tga",
	};

	std::vector<std::string> tex_faces1 = {
		"res/mp_morningdew/morningdew_ft.tga",
		"res/mp_morningdew/morningdew_bk.tga",
		"res/mp_morningdew/morningdew_up.tga",
		"res/mp_morningdew/morningdew_dn.tga",
		"res/mp_morningdew/morningdew_rt.tga",
		"res/mp_morningdew/morningdew_lf.tga",
	};

	unsigned int skytex = loadTexture(tex_faces);
	unsigned int skytex1 = loadTexture(tex_faces1);

	skyboxshader.bind();
	skyboxshader.setInt("skybox", 0);

	std::string exepath = argv[0];
	
	Model mymodel(exepath.substr(0,exepath.find_last_of('\\'))+"\\model\\dragon.obj");
	Model nanosuit(exepath.substr(0, exepath.find_last_of('\\')) + "\\model2\\nanosuit.obj");

	glEnable(GL_DEPTH_TEST);

	//model matrix view matrix projection matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	projection = glm::perspective(glm::radians(45.0f), (float)window.getWidth() / window.getHeight(), 0.01f, 100.0f);
	
	glm::vec3 lightPos(1.0f, 6.0f, 1.5f);



	while (!window.close())
	{
		//get frame time
		window.frameTime();
		
		//key mouse callback
		input.pressKeys(window);

		//clear buffer
		window.clear();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		//skybox
		glDepthMask(GL_FALSE);
		skyboxshader.bind();
		view = glm::mat4(glm::mat3(window.getCamera()->GetViewMatrix())); // remove translation from the view matrix
		skyboxshader.setMat4("view", view);
		skyboxshader.setMat4("projection", projection);
		// skybox cube
		skybox.bind();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, skytex1);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		skybox.unbind();
		glDepthMask(GL_TRUE);




		//render a dragon

		shader.bind();

		glBindTexture(GL_TEXTURE_CUBE_MAP, skytex1);
		view = window.getCamera()->getViewMatrix();
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		shader.setVec3("lightPos", lightPos);
		shader.setVec3("cameraPos", window.getCamera()->Position);
		shader.setInt("skybox", 0);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f)); 
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	
		shader.setMat4("model", model);
		mymodel.Draw(shader);
		
		//nanosuit
		nanosuitshader.bind();
		glBindTexture(GL_TEXTURE_CUBE_MAP, skytex1);
		glm::mat4 model1 = glm::mat4(1.0f);
		model1 = glm::translate(model1, glm::vec3(2.0f,-2.0f,0.0f));
		model1 = glm::scale(model1, glm::vec3(0.2f, 0.2f, 0.2f));
		nanosuitshader.setMat4("model", model1);
		nanosuitshader.setMat4("view", view);
		nanosuitshader.setMat4("projection", projection);
		nanosuitshader.setVec3("lightPos", lightPos);
		nanosuitshader.setVec3("viewPos", window.getCamera()->Position);
		nanosuitshader.setInt("skybox", 0);
		nanosuit.Draw(nanosuitshader);

		//swap buffers poll events
		window.update();
	
	}


	return 0;
}