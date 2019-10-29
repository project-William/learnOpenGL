#pragma once
#include "renderer/Block.h"
#include "Shader.h"

Block::Block()
{
	m_VertexBuffer = std::shared_ptr<VertexBuffer>(new VertexBuffer(sizeof(float) * vertices.size(), &vertices[0]));
	m_VAO.AttribPointer(0, 3, sizeof(float) * 8, 0);
	m_VAO.AttribPointer(1, 3, sizeof(float) * 8, 3 * sizeof(float));
	m_VAO.AttribPointer(2, 2, sizeof(float) * 8, 6 * sizeof(float));
	

}

Block::~Block()
{

}

void Block::Draw(const Shader& shader)
{
	m_VAO.Bind();
	glm::mat4 model = glm::mat4(1.0f);
	shader.SetMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	m_VAO.Unbind();
}