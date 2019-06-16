#include "src/Window.h"
#include "vendor/imGui/imgui.h"
#include "vendor/imGui/imgui_impl_glfw.h"
#include "vendor/imGui/imgui_impl_opengl3.h"
#include "src/graphics/Shader.h"
#include "src/graphics/VertexArray.h"
#include "src/graphics/IndicesBuffer.h"
#include "src/graphics/VertexBuffer.h"

int main() {


	Window window(1200, 700, "window");
	Shader shader("src/shader/triangle_vs.vert", "src/shader/triangle_fs.frag");
	bool tool = true;

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
	ImGui::StyleColorsDark();
	

	float vertices[] = {
		0.5f, 0.5f, 0.0f,  
		0.5f,-0.5f, 0.0f,  
	   -0.5f,-0.5f, 0.0f, 
	   -0.5f, 0.5f, 0.0f   
	};

	unsigned int indices[] = { 
		0, 1, 3, 
		1, 2, 3  
	};

	VertexBuffer vb(sizeof(vertices), vertices);
	VertexArray va;
	IndicesBuffer eb(sizeof(indices), indices);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//rectangle properties
	glm::vec4 rect_color(0.3f,0.9f,0.0f,1.0f);
	glm::vec2 rect_pos(0.0f);


	bool checked = true;
	glm::vec4 clear_color(0.45f, 0.55f, 0.60f, 1.00f);

	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(15.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 view(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection(1.0f);
	projection = glm::perspective(45.0f,
		(float)window.getWidth() / (float)window.getHeight(),
		0.1f,
		100.0f
	);

	glm::mat4 m_MVP = projection * view * model;

	while (!window.close())
	{
		static float f = 0.0f;
		static int counter = 0;

		window.clear();
		//ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		//show imGui window
		{
			ImGui::Begin("Rectangle");
			//ImGui tests
			ImGui::Checkbox("show rectangle", &checked);			
			ImGui::Text("counter=%d", counter);
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)"
				, 1000.0f / ImGui::GetIO().Framerate,
				ImGui::GetIO().Framerate);

			//ImGui functions
			ImGui::ColorEdit3("background", window.getColorArray());
			//draw rectangle
			if (checked) {
				eb.bind();
				shader.bind();
				ImGui::ColorEdit4("rectangle", &rect_color[0]);
				ImGui::SliderFloat2("rectangle position", &rect_pos[0], -0.5f, 0.5f, "-0.5f-0.5f", 1.0f);
				shader.setVec2("rectangle_pos", rect_pos);
				shader.setVec4("rectangle_color", rect_color);
				shader.setMat4("m_MVP", m_MVP);
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				eb.unbind();
			}
			ImGui::End();
		}
		
		//ImGui render
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.bufferUpdate();
	}

	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}