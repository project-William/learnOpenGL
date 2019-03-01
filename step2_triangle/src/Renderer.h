#pragma once
#include <glad/glad.h>


#define ASSERT(function) if(!(function)) __debugbreak();
#define GLCall(function) GLClearError();\
		function;\
		ASSERT(GLLogCall(#function,__FILE__,__LINE__))


void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


class Renderer
{
public:
	void Clear()const;
};

