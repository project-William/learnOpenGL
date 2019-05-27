#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define TEX_NUM 2
#include <string>	

class Texture {
public:
	Texture(GLint ordinal_num, const std::string& name, GLint internalform, GLenum form);
	void UseTexture(GLenum tex, GLint ordinal_num);
	~Texture();
private:
	GLuint texture[TEX_NUM];

};

