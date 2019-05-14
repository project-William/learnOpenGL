#include "vertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);
	glBindVertexArray(0);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_VertexArray);
}

void VertexArray::bind()const {
	glBindVertexArray(m_VertexArray);
}

void VertexArray::unbind()const {
	glBindVertexArray(0);
}