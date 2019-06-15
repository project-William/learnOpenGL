#pragma once
#include <glad/glad.h>
#include "VertexArrayLayout.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

class VertexArrayLayout;
class VertexBuffer;
class VertexArray {
private:
	unsigned int m_VertexObj;
	unsigned int index = 0;
public:
	VertexArray();
	~VertexArray();

	void bind()const;
	void unbind()const;

	unsigned int getIndex()const { return index; }
	void verAttribPtr(const VertexBuffer& vb, const VertexArrayLayout& layout);
};