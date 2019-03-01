#include "vertexArray.h"
#include "Renderer.h"
#include "vertexLayout.h"

vertexArray::vertexArray(){
	GLCall(glGenVertexArrays(1, &m_RendererID));
	GLCall(glBindVertexArray(m_RendererID));
}


vertexArray::~vertexArray(){
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}


void vertexArray::addBuffer(const vertexBuffer & vb, const vertexLayout & layout){
	bind();
	vb.bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalize, layout.getStride(), (const void *)offset));
		offset += element.count * VertexBufferElement::GetTypeSize(element.type);
	}
}

void vertexArray::bind()const {
	GLCall(glBindVertexArray(m_RendererID));
}

void vertexArray::unbind()const {
	GLCall(glBindVertexArray(0));
}