#include "VertexArray.h"

VertexArray::VertexArray()
	:m_VerArray(0)
{
	glGenVertexArrays(1, &m_VerArray);
	glBindVertexArray(m_VerArray);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VerArray);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_VerArray);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
