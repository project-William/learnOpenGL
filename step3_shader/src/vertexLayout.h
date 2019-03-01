#pragma once
#include <glad/glad.h>
#include <vector>

struct VertexBufferElement {
	unsigned int count;
	unsigned int type;
	unsigned char normalize;
	
	static unsigned int GetTypeSize(unsigned int type) {
		switch (type)
		{
		case GL_FLOAT:return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE:return 1;
		}
		return 0;
	}
};


class vertexLayout
{
private:
	std::vector<VertexBufferElement> m_Elemets;
	unsigned int m_Stride;
public:
	vertexLayout();
	~vertexLayout();
	unsigned int getStride()const { return m_Stride; }
	const std::vector<VertexBufferElement> GetElements()const { return m_Elemets; }

	template<typename T> 
	void push(unsigned int count) {
		static_assert(false);
	}

	template<> 
	void push<float>(unsigned int count) {
		m_Elemets.push_back({ count,GL_FLOAT,GL_FALSE });
		m_Stride += count * VertexBufferElement::GetTypeSize(GL_FLOAT);
	}

	template<> 
	void push<unsigned int>(unsigned int count) {
		m_Elemets.push_back({ count,GL_UNSIGNED_INT,GL_FALSE });
		m_Stride += count * VertexBufferElement::GetTypeSize(GL_UNSIGNED_INT);
	}

	template<> 
	void push<unsigned char>(unsigned int count) {
		m_Elemets.push_back({ count,GL_UNSIGNED_BYTE,GL_TRUE });
		m_Stride += count * VertexBufferElement::GetTypeSize(GL_UNSIGNED_BYTE);
	}
};

