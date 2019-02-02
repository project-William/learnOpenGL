#pragma once

#include <iostream>
#include <string>	
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define MAX_TEXTURES 2


class Texture
{
public:
	Texture(GLint ordinal_num, const std::string& tex_name, GLint internalformat, GLenum format);
	void UseTexture(GLenum unit, GLint ordinal_num);
	~Texture();
private:
	unsigned int texture[MAX_TEXTURES];
};





