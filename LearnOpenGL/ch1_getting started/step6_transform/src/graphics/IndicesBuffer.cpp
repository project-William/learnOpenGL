#include "IndicesBuffer.h"

IndicesBuffer::IndicesBuffer(unsigned int size, void* data)
	:m_EleBuffer(0)
{
	glGenBuffers(1, &m_EleBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EleBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

IndicesBuffer::~IndicesBuffer()
{
	glDeleteBuffers(1, &m_EleBuffer);
}

void IndicesBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EleBuffer);
}

void IndicesBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
