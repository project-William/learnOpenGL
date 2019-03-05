#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include <vector>

static unsigned int TypeSize(unsigned int type) {
	if (type == GL_FLOAT)
		return sizeof(float);
	else return 0;
}

struct VertexBufferElements {
	unsigned int count;
	unsigned int type;
	unsigned char normalized;
};

class VertexArrayLayout {
private:

	unsigned int m_Stride;
	unsigned int m_Count;
	std::vector<VertexBufferElements> m_Elements;

public:
	VertexArrayLayout();
	~VertexArrayLayout();
	unsigned int getStride() const { return m_Stride; }
	unsigned int getCount() const { return m_Count; }
	std::vector<VertexBufferElements> getElements()const { return m_Elements; }

	template<typename T>
	void push(unsigned int count) {}
	template<>
	void push<float>(unsigned int count) {
		m_Count = count;
		m_Elements.push_back({ count,GL_FLOAT,GL_FALSE });
		m_Stride += count * TypeSize(GL_FLOAT);
	}
};