#include "Mesh.h"


Mesh::Mesh(std::vector<Vertex>& vertices) 
	:vao(0),vbo(0)
{
	this->m_Vertices = vertices;
	setupMesh();
}


void Mesh::setupMesh() {
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_Vertices.size(), &m_Vertices[0], GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(m_Vertices), (void*)offsetof(Vertex,texCoord));
	//glEnableVertexAttribArray(1);
	

}