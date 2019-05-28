#pragma once
#include <glad/glad.h>


class VertexBuffer {
private:
	unsigned int m_BufferID;
	unsigned int m_ComponentCount;
	unsigned int m_Count;
public:
	VertexBuffer(unsigned int count, void* data, unsigned int componentCount);
	~VertexBuffer();
	
	inline unsigned int getComponentCount()const { return m_ComponentCount; }
	inline unsigned int getCount()const { return m_Count; }

	void bind() const;
	void unbind() const;

};