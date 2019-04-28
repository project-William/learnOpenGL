#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(3, m_Buffer);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(3, m_Buffer);
}

void VertexBuffer::bind(int num) const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Buffer[num]);
}

void VertexBuffer::unbind(int num) const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void VertexBuffer::push(unsigned int size, const void* data) {
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}