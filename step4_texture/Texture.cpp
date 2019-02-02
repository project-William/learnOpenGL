#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Texture::Texture(GLint ordinal_num, const std::string& tex_name, GLint internalformat, GLenum format)
{
	glGenTextures(1, &texture[ordinal_num]);
	glBindTexture(GL_TEXTURE_2D, texture[ordinal_num]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int tex_width, tex_height, nrChannels;
	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(tex_name.c_str(), &tex_width, &tex_height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, internalformat, tex_width, tex_height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture!" << std::endl;
	}
	stbi_image_free(data);

}

void Texture::UseTexture(GLenum unit,GLint ordinal_num) {
	glActiveTexture(unit);
	glBindTexture(GL_TEXTURE_2D, texture[ordinal_num]);
}


Texture::~Texture()
{
}
