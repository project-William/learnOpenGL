#pragma once
#include <glad/glad.h>

namespace flappy {
	namespace graphics {
		class VertexBuffer {
		private:
			unsigned int m_VBO;
		public:
			VertexBuffer():m_VBO(0){}
			VertexBuffer(unsigned int size, void* data);
			~VertexBuffer();

			void bind()const;
			void unbind()const;
		};
	}
}





