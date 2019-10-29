#include "renderer/Shadow.h"
#include "Shader.h"

Shadow::Shadow()
{

}

Shadow::~Shadow()
{

}


void Shadow::Init(unsigned int texture)
{
	glGenFramebuffers(1, &m_DepthMapFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, m_DepthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

void Shadow::RenderShadow(const glm::vec3& lightPos, Shader& shader,std::function<void()> func)
{
	glm::mat4 lightProjection, lightView;
	lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
	lightView = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	lightSpaceMatrix = lightProjection * lightView;

	shader.UseProgram();
	shader.SetMat4("lightSpaceMatrix", lightSpaceMatrix);

	glViewport(0, 0, 1024, 1024);
	glBindFramebuffer(GL_FRAMEBUFFER, m_DepthMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);
	
	func();
	//tex.UseTexture();
	//block->Draw(simpleDepthShader);
	//board->Draw(simpleDepthShader);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);


}
