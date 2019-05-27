#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(unsigned int size,const void* data)
	:m_Size(size)
{
	GLCall(glGenBuffers(1, &m_Buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_Buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
	GLCall(glDeleteBuffers(1, &m_Buffer));
}

void VertexBuffer::bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_Buffer));
}

void VertexBuffer::unbind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
