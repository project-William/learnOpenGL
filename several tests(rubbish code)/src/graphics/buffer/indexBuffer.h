#pragma once
#include <glad/glad.h>

class IndexBuffer {
private:
	unsigned int m_IndexBuffer;
public:
	IndexBuffer(unsigned int size, void* data);
	~IndexBuffer();

	void bind()const;
	void unbind()const;
};