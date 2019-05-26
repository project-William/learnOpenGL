#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"

namespace flappy {
	namespace graphics {
		Texture::Texture(const std::string& filepath,int index)
			:m_Filepath(filepath),m_Index(index)
		{
			glGenTextures(1, &m_Texture);
			glBindTexture(GL_TEXTURE_2D, m_Texture);
			load();
		}

		void Texture::load() {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			int m_TexWidth, m_TexHeight, m_Comp;
			stbi_set_flip_vertically_on_load(true);
			unsigned char* m_Data = stbi_load(m_Filepath.c_str(), &m_TexWidth, &m_TexHeight, &m_Comp, 0);
			if (m_Data) {
				if (m_Index == 0) {
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_TexWidth, m_TexHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
				}
				else if (m_Index == 1) {
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_TexWidth, m_TexHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Data);
				}
				else if (m_Index == 2) {
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_TexWidth, m_TexHeight, 0, GL_RGB8, GL_UNSIGNED_BYTE, m_Data);
				}
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else {
				std::cout << "failed" << std::endl;
			}
			stbi_image_free(m_Data);
		}

		void Texture::bind() const {
			glBindTexture(GL_TEXTURE_2D, m_Texture);
		}

		void Texture::unbind() const {
			glBindTexture(GL_TEXTURE_2D, 0);
		}

	}
}
