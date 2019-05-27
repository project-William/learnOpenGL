#pragma once
#include <glad/glad.h>
#include "VertexLayout.h"



class Render {
private:
public:
	void clear(float x, float y, float z, float w)const;
	void draw(const VertexLayout& layout);
};

void Render::clear(float x, float y, float z, float w)const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(x, y, z, w);
}

void Render::draw(const VertexLayout& layout) {
	glDrawArrays(GL_TRIANGLES, 0, layout.getVerNum());
}

