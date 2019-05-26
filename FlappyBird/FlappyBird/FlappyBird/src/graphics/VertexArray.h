#pragma once
#include <glad/glad.h>

namespace flappy {
	namespace graphics {
		class VertexArray {
		private:
			unsigned int m_VAO;
		public:
			VertexArray();
			~VertexArray();

			void bind()const;
			void unbind()const;
		};
	}
}


