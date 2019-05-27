#pragma once
#include <iostream>
#include <glad/glad.h>
#include <vector>

struct Elements
{
	unsigned int index;
	unsigned int count;
	unsigned int offset;
};

class VertexLayout {
private:
	std::vector<Elements> m_VertexLayout;
	unsigned int m_Stride;
	unsigned int m_Count;
	unsigned int m_Offset;
	int m_NumVer;
public:
	VertexLayout(int num_ver, unsigned int size)
		:m_Stride(0),m_Count(0),m_VertexLayout(0),m_Offset(0),m_NumVer(num_ver)
	{
		m_Stride = calStride(num_ver, size);
	}
	~VertexLayout(){}
	inline unsigned int GetStride()const { return m_Stride; }
	inline std::vector<Elements> GetElements()const { return m_VertexLayout; }
	unsigned int& calStride(int num_ver, unsigned int size) {
		m_Stride = size / num_ver;
		return m_Stride;
	}
	unsigned int getVerNum()const { return m_NumVer ; }
	unsigned int GetCount()const { return m_Count; }
	template<typename T>
	void push(unsigned int index, unsigned int count);
	template<>
	void push<float>(unsigned int index, unsigned int count) {
		m_VertexLayout.push_back({ index, count, m_Offset });
	}
};