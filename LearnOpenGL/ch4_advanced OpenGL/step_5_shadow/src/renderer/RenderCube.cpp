#include "renderer/RenderCube.h"

RenderCube::RenderCube(const std::string& vfile,const std::string& ffile)
{
	m_Shader = std::shared_ptr<Shader>(new Shader(vfile, ffile));
	m_VBO = std::shared_ptr<VertexBuffer>(new VertexBuffer(sizeof(float) * vertices.size(), &vertices[0]));
	m_VAO = std::shared_ptr<VertexArray>(new VertexArray());
	m_VAO->AttribPointer(0, 3, 6 * 4, 0);
	m_VAO->AttribPointer(1, 3, 6 * 4, 3 * 4);

}

RenderCube::~RenderCube()
{

}


void RenderCube::Draw(WindowPros& windata, std::shared_ptr<Camera> camera)
{
	m_VAO->Bind();
	m_Shader->UseProgram();

	projection = glm::perspective(glm::radians(45.0f), (float)windata.m_Width / windata.m_Height, 0.1f, 100.0f);
	view = glm::mat4(1.0f);
	view = camera->GetViewMatrix();
	model = glm::mat4(1.0f);

	m_Shader->SetMat4("projection", projection);
	m_Shader->SetMat4("view", view);
	m_Shader->SetMat4("model", model);

	glDrawArrays(GL_TRIANGLES, 0, 36);


}

