#pragma once
#include <glad/glad.h>
#include <string>
#include "Renderer.h"
#include <memory>



class Texture {
private:
	std::string m_TexPath;
	unsigned int m_Texture;
	unsigned char* m_Data;
	int width, height, nrchannel;
public:
	Texture(const std::string& texpath);
	~Texture();
	void bind()const;
	void unbind()const;
	void format(unsigned int format);
	void useTexture(unsigned int texnum);
private:
	unsigned int genTexture();
};