#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include "Window.h"
#include "Shader.h"

class Coordinate {
private:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 m_MVP;
	Shader m_Shader;
public:
	Coordinate(Shader& shader, Window& window)
		:model(glm::mat4(1.0f)),view(glm::mat4(1.0f)),
		projection(glm::mat4(1.0f)),m_Shader(shader)
	{
		projection = glm::perspective(glm::radians(window.camera->Zoom), 
			(float)window.GetWidth() / (float)window.GetHeight(), 0.1f, 100.0f);
		view = window.camera->GetViewMatrix();
		m_Shader.SetMat4("model", model);
		m_Shader.SetMat4("view", view);
		m_Shader.SetMat4("projection", projection);

	}

	void resetMVP(const glm::vec3& pos,const glm::vec3& scale) {
		model = glm::translate(model, pos);
		model = glm::scale(model, scale);

		m_Shader.SetMat4("model", model);
		m_Shader.SetMat4("view", view);
		m_Shader.SetMat4("projection", projection);

	}

	~Coordinate() {}
};