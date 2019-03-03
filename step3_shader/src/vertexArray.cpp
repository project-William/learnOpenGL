#include "VertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &m_VertexObj);
	glBindVertexArray(m_VertexObj);

}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_VertexObj);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_VertexObj);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::verAttribPtr(const VertexBuffer& vb, const VertexArrayLayout& layout){
	bind();
	vb.bind();
	const auto& elements = layout.getElements();
	glVertexAttribPointer(index, 
		elements[index].count, 
		elements[index].type,
		elements[index].normalized, 
		layout.getStride(),
		(const void*)(index* TypeSize(GL_FLOAT)));
	glEnableVertexAttribArray(index);
}

