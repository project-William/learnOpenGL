#include "VertexArray.h"
#include "Renderer.h"
VertexArray::VertexArray() {
	GLCall(glGenVertexArrays(1, &m_VertexObj));
	GLCall(glBindVertexArray(m_VertexObj));

}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_VertexObj));
}

void VertexArray::bind() const
{
	GLCall(glBindVertexArray(m_VertexObj));
}

void VertexArray::unbind() const
{
	GLCall(glBindVertexArray(0));
}

void VertexArray::verAttribPtr(const VertexBuffer& vb, const VertexArrayLayout& layout){
	bind();
	vb.bind();
	const auto& elements = layout.getElements();
	GLCall(glVertexAttribPointer(index,
		elements[index].count, 
		elements[index].type,
		elements[index].normalized, 
		layout.getStride(),
		(const void*)(index* TypeSize(GL_FLOAT))));
	GLCall(glEnableVertexAttribArray(index));
}

