#pragma once
#include <glad/glad.h>

class VertexArray {
private:
	unsigned int m_VertexArray;
public:
	VertexArray();
	~VertexArray();

	void bind()const;
	void unbind()const;

};