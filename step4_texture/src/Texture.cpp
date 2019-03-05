#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(const std::string& texpath)
	:m_TexPath(texpath),width(0),height(0),nrchannel(0),m_Data(nullptr)
{
	m_Texture = genTexture();
}

Texture::~Texture() {
	glDeleteTextures(1, &m_Texture);
}

void Texture::bind()const {
	glBindTexture(GL_TEXTURE_2D, m_Texture);
}

void Texture::unbind()const {
	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::genTexture(){
	unsigned int tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	//parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}

void Texture::format(unsigned int format) {
	m_Data = stbi_load(m_TexPath.c_str(), &width, &height, &nrchannel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, m_Data);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::useTexture(unsigned int texnum){
	glActiveTexture(texnum);
	bind();
}
