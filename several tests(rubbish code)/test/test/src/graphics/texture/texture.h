#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "utils/stb_image.h"

class Texture {
private:
	unsigned int m_Texture;
	int m_TexWidth, m_TexHeight, m_Nrchannels;
	std::string m_FilePath;
public:
	Texture(const std::string& filepath);
	~Texture();

	void useTexture(unsigned int slot);

};


Texture::Texture(const std::string& filepath) 
	:m_FilePath(filepath)
{ 
	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_2D, m_Texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrchannel;
	unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &nrchannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

}



Texture::~Texture() {
	
}

void Texture::useTexture(unsigned int slot) {
	glActiveTexture(GL_TEXTURE0 + slot);
}