#pragma once
#include <glad/glad.h>
#include "vertexBuffer.h"

class vertexLayout;

class vertexArray
{
private:
	unsigned int m_RendererID;
public:
	vertexArray();
	~vertexArray();

	void addBuffer(const vertexBuffer& vb, const vertexLayout& layout);
	void bind()const;
	void unbind()const;
};

