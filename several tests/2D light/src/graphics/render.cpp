#include "render.h"


void Render::draw(VertexArray& vao) {
	vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	vao.unbind();
}