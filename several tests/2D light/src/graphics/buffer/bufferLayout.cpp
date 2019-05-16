#include "bufferLayout.h"


BufferLayout::BufferLayout() {

}

BufferLayout::~BufferLayout() {

}

void BufferLayout::addBuffer(VertexArray& vao, VertexBuffer& vbo, int index) const {
	vbo.bind();
	vao.bind();
	glVertexAttribPointer(index, vbo.getComponentCount(),
		GL_FLOAT, GL_FALSE,
		vbo.getComponentCount() * sizeof(float), (void*)0);
	glEnableVertexAttribArray(index);
	
	vao.unbind();
	vbo.unbind();
}
