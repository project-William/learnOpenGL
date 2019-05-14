#include "bufferLayout.h"


BufferLayout::BufferLayout() {

}

BufferLayout::~BufferLayout() {

}

void BufferLayout::addBuffer(VertexArray& vao, VertexBuffer& vbo) const {
	vbo.bind();
	vao.bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}
