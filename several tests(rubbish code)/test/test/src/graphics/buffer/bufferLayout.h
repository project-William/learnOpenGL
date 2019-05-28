#pragma once
#include <glad/glad.h>
#include "vertexArray.h"
#include "vertexBuffer.h"

class BufferLayout {
public:
	BufferLayout();
	~BufferLayout();
	
	void addBuffer(VertexArray& vao,VertexBuffer& vbo, int index)const;
};
