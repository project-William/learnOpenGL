#include "Renderer.h"

void GLClearError() {
	while (glGetError()!=GL_NO_ERROR){}
}

bool GLLogCall(const char* function,const char* file,int line) {
	while (GLenum error=glGetError()){
		std::cout << "[OpenGL]: " << "(" << error << ")" << std::endl;
		std::cout << "function: " << function << std::endl;
		std::cout << "line: " << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::clear(float r,float g,float b,float a)const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	GLCall(glClearColor(r, g, b, a));
}