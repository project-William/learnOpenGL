#pragma once
#include <glad/glad.h>

class IndicesBuffer {
private:
	unsigned int m_EleBuffer;
public:
	IndicesBuffer() :m_EleBuffer(0){};
	IndicesBuffer(unsigned int size, void* data);
	~IndicesBuffer();

	void bind()const;
	void unbind()const;
};