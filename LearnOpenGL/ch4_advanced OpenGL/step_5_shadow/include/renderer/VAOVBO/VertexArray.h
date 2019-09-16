#pragma once
#include <glad/glad.h>


class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void AttribPointer(int index, unsigned int size, unsigned int stride, unsigned int offset);

private:
	GLuint m_VAO;


};