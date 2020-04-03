#pragma once
#include "BufferLayout.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"

namespace gltoys::opengl
{
	class VertexArray
	{
	private:
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		GLuint m_VertexArray;
	public:
		VertexArray(size_t size, const void* data);
		~VertexArray();
		void CreateEBO(size_t indices_size, const void* indices_data);

		void AddBufferLayout(const BufferLayout& layout);

		void BindVertexArray()const;
		void UnbindVertexArray()const;

	};
}