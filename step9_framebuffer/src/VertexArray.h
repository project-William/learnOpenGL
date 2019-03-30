#pragma once
#include <glad/glad.h>
#include "VertexLayout.h"

class VertexArray {
private:
	unsigned int m_VertexArray[2];
public:
	VertexArray();
	~VertexArray();

	void addBuffer(const VertexLayout& layout);
	void bind(int num)const;
	void unbind()const;
};