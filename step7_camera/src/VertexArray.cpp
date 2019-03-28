#include "VertexArray.h"

VertexArray::VertexArray()
	:m_VertexArray(0)
{
	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VertexArray);
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

void VertexArray::bind() const
{
	glBindVertexArray(m_VertexArray);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
