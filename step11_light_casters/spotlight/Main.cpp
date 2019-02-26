#include "Window.h"
#include "Texture.h"
#include "Shader.h"
#include "vertex_data.h"

int main() {
	Window window("fuck", 1200, 800);
	Shader light_shader("light_vert.vert","light_frag.frag");
	Shader lamp_shader("lamp_vert.vert","lamp_frag.frag");

	glEnable(GL_DEPTH_TEST);

	unsigned int VBO, cubeVAO;
	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(cubeVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	Texture tex;

	unsigned int diffuseMap = tex.load_texture("container2.png");
	unsigned int specularMap = tex.load_texture("container2_specular.png");

	light_shader.useprogram();
	light_shader.setInt("material.diffuse", 0);
	light_shader.setInt("material.specular", 1);

	glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

	while (!window.closed())
	{
		float currentFrame = glfwGetTime();
		window.deltaTime = currentFrame - window.lastFrame;
		window.lastFrame = currentFrame;

		window.processInput(window.m_window);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		window.clear();

		//active shader
		light_shader.useprogram();
		light_shader.setVec3("light.position", window.camera.Position);
		light_shader.setVec3("light.direction", window.camera.Front);
		light_shader.setFloat("light.cutOff", glm::cos(glm::radians(13.5f)));
		light_shader.setVec3("viewPos", window.camera.Position);


		// light properties
		light_shader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
		light_shader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
		light_shader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
		light_shader.setFloat("light.constant", 1.0f);
		light_shader.setFloat("light.linear", 0.09f);
		light_shader.setFloat("light.quadratic", 0.032f);

		light_shader.setFloat("material.shininess", 32.0f);

		glm::mat4 projection = glm::perspective(glm::radians(window.camera.Zoom), (float)window.m_width / (float)window.m_height, 0.1f, 100.0f);
		glm::mat4 view = window.camera.GetViewMatrix();

		//render light
		light_shader.setMat4("projection", projection);
		light_shader.setMat4("view", view);

		glm::mat4 model = glm::mat4(1.0f);
		light_shader.setMat4("model", model);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularMap);

		glBindVertexArray(cubeVAO);
		for (unsigned int i = 0; i < 10; i++)
		{
			// calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			light_shader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}


		//render lamp
		lamp_shader.useprogram();
		lamp_shader.setMat4("projection", projection);
		lamp_shader.setMat4("view", view);
		model = glm::mat4(1.0f);
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.3f));
		lamp_shader.setMat4("model", model);

		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		window.update();
	}

	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}


