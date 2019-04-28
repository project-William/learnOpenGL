#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(3, m_VertexArray);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(3, m_VertexArray);
}

void VertexArray::addBuffer(const VertexLayout& layout) {
	auto elements = layout.GetElements();
	auto offset = elements[0].offset;
	for (int i = 0; i < elements.size(); i++) {
		glVertexAttribPointer(i, elements[i].count, GL_FLOAT, GL_FALSE, layout.GetStride(), (void*)(offset*4));
		glEnableVertexAttribArray(i);
		offset += elements[i].count;
	}
}

void VertexArray::bind(int num) const
{
	glBindVertexArray(m_VertexArray[num]);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
