#pragma once
#include <glad/glad.h>
#include "buffer/indexBuffer.h"
#include "buffer/vertexArray.h"
#include "buffer/vertexBuffer.h"

class Render {
public:
	Render(){}
	~Render(){}
	void draw(VertexArray& vao);

};