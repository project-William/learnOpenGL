#include "OpenGL/VertexBuffer.h"

namespace gltoys::opengl
{
	VertexBuffer::VertexBuffer(size_t size, const void* data)
		:m_VertexBufferID(0)
	{
		glGenBuffers(1, &m_VertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_VertexBufferID);
	}

	void VertexBuffer::AddBufferData(size_t size, void* data)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void VertexBuffer::AddSubBufferData(size_t size, size_t offset, void* data)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	}

	void VertexBuffer::BindVertexBuffer()const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
	}

	void VertexBuffer::UnbindVertexBuffer()const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}