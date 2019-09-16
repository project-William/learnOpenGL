#include "..//graphics/VertexArray.h"

namespace flappy {
	namespace graphics {
		VertexArray::VertexArray() {
			glGenVertexArrays(1, &m_VAO);
			glBindVertexArray(m_VAO);
			glBindVertexArray(0);
		}

		VertexArray::~VertexArray() {
			glDeleteVertexArrays(1, &m_VAO);
		}

		void VertexArray::bind()const {
			glBindVertexArray(m_VAO);
		}

		void VertexArray::unbind()const {
			glBindVertexArray(0);
		}
	}
}