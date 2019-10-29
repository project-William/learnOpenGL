#include "Window.h"
#include "renderer/Block.h"
#include "renderer/Board.h"
#include "Shader.h"
#include "Texture.h"
#include "renderer/Shadow.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = (float)1280 / 2.0;
float lastY = (float)720/ 2.0;
bool firstMouse = true;

// timing
float deltaTime = 0.1f;
float lastFrame = 0.0f;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{

	Window::Create(1280, 720, "shadow");
	auto window = Window::GetWindowInstance();
	glfwSetFramebufferSizeCallback(window->GetWindowPros().m_Window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window->GetWindowPros().m_Window, mouse_callback);
	glfwSetScrollCallback(window->GetWindowPros().m_Window, scroll_callback);


	Texture shadow_texture;
	shadow_texture.GenerateDepthMap();

	Shadow shadow;
	
	std::shared_ptr<Block> block(new Block());
	std::shared_ptr<Board> board(new Board());

	glEnable(GL_DEPTH_TEST);

	Shader shader("shader/block.vert", "shader/block.frag");
	Shader simpleDepthShader("shader/shadow.vert", "shader/shadow.frag");
	Shader debugDepthQuad("shader/debugquad.vert", "shader/debugfragment.frag");

	
	Texture tex("resource/wood.png");

	shadow.Init(shadow_texture.GetTExture());

	shader.UseProgram();
	shader.SetInt("diffuseTexture", 0);
	shader.SetInt("shadowMap", 1);


	debugDepthQuad.UseProgram();
	debugDepthQuad.SetInt("depthMap", 0);


	glm::vec3 lightPos(-2.0f, 4.0f, -1.0f);

	while (!window->Closed())
	{
		processInput(window->GetWindowPros().m_Window);
		window->Clear();

		shadow.RenderShadow(lightPos, simpleDepthShader, [&]()
		{
			tex.UseTexture(0);
			block->Draw(simpleDepthShader);
			board->Draw(simpleDepthShader);
		});

		glViewport(0, 0, window->GetWinWidth(), window->GetWinHeight());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		shader.UseProgram();
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)window->GetWinWidth() / window->GetWinHeight(), 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		shader.SetMat4("projection", projection);
		shader.SetMat4("view", view);

		shader.SetVec3("viewPos", camera.Position);
		shader.SetVec3("lightPos", lightPos);
		shader.SetMat4("lightSpaceMatrix", shadow.GetLightSpaceMatrix());

		tex.UseTexture(0);
		shadow_texture.UseTexture(1);
		block->Draw(shader);
		board->Draw(shader);

		debugDepthQuad.UseProgram();
		debugDepthQuad.SetFloat("near_plane", shadow.near_plane);
		debugDepthQuad.SetFloat("far_plane", shadow.far_plane);
		shadow_texture.UseTexture(0);

		window->Update();
	}


	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}