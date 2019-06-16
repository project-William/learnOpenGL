#pragma once
#include <glad/glad.h>

class VertexBuffer {
private:
	unsigned int m_Buffer;
public:
	VertexBuffer():m_Buffer(0){}
	VertexBuffer(unsigned int size, void* data);
	~VertexBuffer();

	void bind()const;
	void unbind()const;
};