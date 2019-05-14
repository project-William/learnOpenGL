#pragma once
#include <glad/glad.h>


class VertexBuffer {
private:
	unsigned int m_BufferID;
public:
	VertexBuffer(unsigned int size, void* data);
	~VertexBuffer();
		
	void bind() const;
	void unbind() const;

};