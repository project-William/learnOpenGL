#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>


struct Vertex {
	glm::vec3 position;
	//glm::vec3 normal;
	//glm::vec2 texCoord;
};

struct Texture {
	std::string type;
	int id;
};



class Mesh {
private:
	std::vector<Vertex> m_Vertices;
	std::vector<Texture> m_Texture;
	unsigned int vao, vbo;
	
	//std::vector<int> m_Indices;
public:

	Mesh(std::vector<Vertex>& vertices);

	

	void setupMesh();

};