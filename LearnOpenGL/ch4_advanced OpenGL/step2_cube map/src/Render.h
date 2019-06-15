#pragma once
#include <glad/glad.h>
#include "VertexLayout.h"
#include "Shader.h"


class Render {
private:

public:
	void clear(float x, float y, float z, float w)const;
	void draw(const VertexLayout& layout);
	//phong reflection model
	void PhongReflection(glm::vec3& lightPos, const Window& window,const Shader& shader) {

		shader.SetVec3("light.position", lightPos);
		shader.SetVec3("viewPos", window.camera->Position);

		shader.SetVec3("material.ambient", 0.5f, 0.5f, 0.5f);
		shader.SetVec3("light.ambient", 0.4f, 0.4f, 0.4f);
		shader.SetVec3("light.diffuse", 1.0f, 1.0f, 1.0f);
		shader.SetVec3("light.specular", 1.0f, 1.0f, 1.0f);
		
		shader.SetVec3("material.specular", 0.5f, 0.5f, 0.5f);
		shader.SetFloat("material.shininess", 64.0f);
	}
};

void Render::clear(float x, float y, float z, float w)const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(x, y, z, w);
}

void Render::draw(const VertexLayout& layout) { 
	glDrawArrays(GL_TRIANGLES, 0, layout.getVerNum());
}

