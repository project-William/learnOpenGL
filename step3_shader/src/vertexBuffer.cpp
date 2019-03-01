#include "vertexBuffer.h"
#include "Renderer.h"


vertexBuffer::vertexBuffer(unsigned int size, const void* data)
	:m_Size(size)
{
	GLCall(glGenBuffers(1, &m_RendererID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}


vertexBuffer::~vertexBuffer(){
	
}

void vertexBuffer::bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void vertexBuffer::unbind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
