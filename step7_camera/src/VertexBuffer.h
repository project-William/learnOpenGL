#pragma once
#include <glad/glad.h>


class VertexBuffer {
private:
	unsigned int m_Buffer;
public:

	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();
	void bind()const;
	void unbind()const;
};