#include "Window.h"

#include "Shader.h"
#include "vertex_data.h"
#include "Texture.h"

int main() {
	Window window("fuck", 1200, 800);
	Shader myshader("vert.txt", "frag.txt");

	glEnable(GL_DEPTH_TEST);

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Texture tex("container.jpg", "awesomeface.png");
	
	myshader.useprogram();
	myshader.setInt("texture1", 0);
	myshader.setInt("texture2", 1);

	while (!window.closed())
	{
		float currentFrame = glfwGetTime();
		window.deltaTime = currentFrame - window.lastFrame;
		window.lastFrame = currentFrame;

		window.processInput(window.m_window);

		glClearColor(0.2f, 0.4f, 1.0f, 1.0f);
		window.clear();
		//texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex.texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex.texture2);

		myshader.useprogram();
		glm::mat4 projection = glm::perspective(glm::radians(window.camera.Zoom), (float)window.m_width / (float)window.m_height, 0.1f, 100.0f);
		myshader.setMat4("projection", projection);

		glm::mat4 view = window.camera.GetViewMatrix();
		myshader.setMat4("view", view);

		glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 10; i++)
		{

			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			myshader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		window.update();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}


