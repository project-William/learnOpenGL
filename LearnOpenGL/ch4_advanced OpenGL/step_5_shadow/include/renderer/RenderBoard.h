#pragma once
#include "renderer/VAOVBO/VertexArray.h"
#include "renderer/VAOVBO/VertexBuffer.h"
#include "..//Shader.h"
#include "Window.h"

class RenderBoard
{
public:
	RenderBoard(const std::string& vfile, const std::string& ffiles);
	~RenderBoard();

	void Draw(WindowPros& windata);
private:
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<VertexBuffer> m_VBO;
	std::shared_ptr<VertexArray> m_VAO;

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;

	std::vector<float> vertices =
	{
		-1.0f,0.0f,1.0f,
		-1.0f,0.0f,-1.0f,
		1.0f,0.0f,-1.0f,
		1.0f,0.0f,-1.0f,
		1.0f,0.0f,1.0f,
		-1.0f,0.0f,1.0f,
	};

};