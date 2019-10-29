#pragma once
#include "Common.h"


class VertexBuffer
{
public:
	explicit VertexBuffer(unsigned int size, void* data);
	~VertexBuffer();

	void Bind() const;
	void Unbind()const;
private:
	unsigned int m_VBO;
};

