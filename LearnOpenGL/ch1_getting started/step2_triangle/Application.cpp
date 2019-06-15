#include "src/Window.h"
#include "vendor/imGui/imgui.h"
#include "vendor/imGui/imgui_impl_glfw.h"
#include "vendor/imGui/imgui_impl_opengl3.h"
#include "src/graphics/Shader.h"
int main() {

	Window window(1200, 700, "window");
	Shader shader("src/shader/triangle_vs.vert", "src/shader/triangle_fs.frag");

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
	ImGui::StyleColorsDark();

	float vertices[] = {
		-0.5f,-0.5f,0.0f,
		 0.5f,-0.5f,0.0f,
		-0.0f, 0.5f,0.0f,
	};

	unsigned int vao, vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//trinagle properties
	glm::vec4 tri_color(1.0);
	glm::vec2 tri_pos(0.0f);


	while (!window.close())
	{
		window.clear();
		//ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		//ImGui functions
		ImGui::ColorEdit3("clear color", window.getColorArray());
		//draw triangle
		glBindVertexArray(vao);
		shader.bind();
		ImGui::ColorEdit4("triangle", &tri_color[0]);
		ImGui::SliderFloat2("triangle position", &tri_pos[0], -0.5f, 0.5f, "-0.5f-0.5f", 1.0f);
		shader.setVec2("triangle_pos", tri_pos);
		shader.setVec4("triangle_color", tri_color);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

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