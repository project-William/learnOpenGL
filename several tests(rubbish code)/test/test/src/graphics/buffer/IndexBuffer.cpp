#include "indexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int size, void* data) {
	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

IndexBuffer::~IndexBuffer() {
	glDeleteBuffers(1, &m_IndexBuffer);
}

void IndexBuffer::bind()const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
}

void IndexBuffer::unbind()const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
