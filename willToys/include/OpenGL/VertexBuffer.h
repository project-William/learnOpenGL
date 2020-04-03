#pragma once
#include "..//Common.h"

namespace gltoys::opengl
{
	class VertexBuffer
	{
	public:
		VertexBuffer() :m_VertexBufferID(0) {}
		VertexBuffer(size_t size, const void* data);
		~VertexBuffer();
		
		void BindVertexBuffer()const;
		void UnbindVertexBuffer()const;

		void AddBufferData(size_t size, void* data);
		void AddSubBufferData(size_t size, size_t offset, void* data);

	private:
		GLuint m_VertexBufferID;
	};
}