#pragma once

#include <glad/glad.h>

class vertexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Size;
public:
	vertexBuffer(unsigned int size,const void* data);
	~vertexBuffer();
	
	inline const int getSize()const { return m_Size; }
	void bind()const;
	void unbind()const;
};

