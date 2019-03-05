#pragma once
#include <glad/glad.h>



class VertexBuffer {
private:
	unsigned int m_Buffer;
	unsigned int m_Size;
public:
	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	unsigned int getSize()const { return m_Size; }
	void bind()const;
	void unbind()const;
};