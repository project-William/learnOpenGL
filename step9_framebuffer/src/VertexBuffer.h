#pragma once
#include <glad/glad.h>
#include <vector>

class VertexBuffer {
private:
	unsigned int m_Buffer[2];
public:

	VertexBuffer();
	~VertexBuffer();
	void bind(int num)const;
	void unbind(int num)const;

	void push(unsigned int size, const void* data);
};