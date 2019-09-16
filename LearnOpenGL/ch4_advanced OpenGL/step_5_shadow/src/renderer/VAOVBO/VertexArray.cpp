#include "renderer/VAOVBO/VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VAO);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_VAO);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::AttribPointer(int index, unsigned int size, unsigned int stride, unsigned int offset)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
}

