#include "vertexBuffer.h"

VertexBuffer::VertexBuffer(unsigned int size,void* data) {
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_BufferID);
}

void VertexBuffer::bind()const {
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void VertexBuffer::unbind()const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


