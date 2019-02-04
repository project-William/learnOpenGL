#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(GLint ordinal_num,const std::string& name, GLint internalform, GLenum form) {

	glGenTextures(1, &texture[ordinal_num]);
	glBindTexture(GL_TEXTURE_2D, texture[ordinal_num]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int tex_width, tex_height, nrchannel;
	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(name.c_str(), &tex_width, &tex_height, &nrchannel, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, internalform, tex_width, tex_height, 0, form, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture!" << std::endl;
	}

	stbi_image_free(data);
}

void Texture::UseTexture(GLenum tex,GLint ordinal_num) {

	glActiveTexture(tex);
	glBindTexture(GL_TEXTURE_2D, texture[ordinal_num]);
}


Texture::~Texture() {

}





