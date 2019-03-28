#pragma once
#include <glad/glad.h>
#include "VertexLayout.h"

class VertexArray {
private:
	unsigned int m_VertexArray;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(const VertexLayout& layout);
	void bind()const;
	void unbind()const;
};