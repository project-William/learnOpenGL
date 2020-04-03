#pragma once
#include "..//Common.h"

namespace gltoys::opengl
{
	class IndexBuffer
	{
	private:
		GLuint m_IndexBufferID;
	public:
		IndexBuffer(size_t size, const void* data);
		~IndexBuffer();

		void BindIndexBuffer()const;
		void UnbindIndexBuffer()const;
	};
}