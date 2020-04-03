#include "OpenGL/IndexBuffer.h"

namespace gltoys::opengl
{
	IndexBuffer::IndexBuffer(size_t size, const void* data)
		: m_IndexBufferID(0)
	{
		glGenBuffers(1, &m_IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_IndexBufferID);
	}

	void IndexBuffer::BindIndexBuffer()const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
	}

	void IndexBuffer::UnbindIndexBuffer()const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}