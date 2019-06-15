#pragma once
#include <glad/glad.h>

//abstract class of texture with functions that must be manipulated in subclasses
//like Texture2D.h and Texture3D.h
class Texture {
public:
	Texture(){}
	virtual ~Texture(){}

	virtual void bind(unsigned int slot)const = 0;
	virtual void unbind()const = 0;

	virtual inline int GetTexWidth()const = 0;
	virtual inline int GetTexHeight()const = 0;
};

//subclass Texture2D and Texture3D
class Texture2D : public Texture {
private:
	unsigned int m_Texture2D;
	unsigned char* m_LocalBuffer;
	int width, height, nrchannel;
public:
	Texture2D(const std::string& filepath)
		:m_Texture2D(0), width(0), height(0), m_LocalBuffer(NULL)
	{

		stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer = stbi_load(filepath.c_str(), &width, &height, &nrchannel, 4);

		glGenTextures(1, &m_Texture2D);
		glBindTexture(GL_TEXTURE_2D, m_Texture2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);

		glBindTexture(GL_TEXTURE_2D, 0);

		if (m_LocalBuffer)
			stbi_image_free(m_LocalBuffer);
	}
	~Texture2D() {
		glDeleteTextures(1, &m_Texture2D);
	}

	void bind(unsigned int slot = 0)const override {
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_Texture2D);
	}
	void unbind()const override {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	inline int GetTexWidth()const override { return width; }
	inline int GetTexHeight()const override { return height; }
};
//texture3D
class Texture3D :public Texture {
private:
	unsigned int m_Texture3D;
	unsigned char* m_LocalBuffer;
	int width, height, nrchannel;
	std::vector<std::string> textures_faces;

public:
	Texture3D(const std::string& filepath1,
		const std::string& filepath2,
		const std::string& filepath3,
		const std::string& filepath4,
		const std::string& filepath5,
		const std::string& filepath6);
	~Texture3D();

	inline int GetTexWidth()const override { return width; }
	inline int GetTexHeight()const override { return height; }
	inline std::vector<std::string> GetTextureFaces()const { return textures_faces; }

	void bind(unsigned int slot = 0)const override {
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_Texture3D);
	}

	void unbind()const override {
		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	}

};

Texture3D::Texture3D(const std::string& filepath1,
	const std::string& filepath2,
	const std::string& filepath3,
	const std::string& filepath4,
	const std::string& filepath5,
	const std::string& filepath6)
	:m_Texture3D(0), m_LocalBuffer(nullptr), width(0), height(0), nrchannel(0)
{
	textures_faces.push_back(filepath1);
	textures_faces.push_back(filepath2);
	textures_faces.push_back(filepath3);
	textures_faces.push_back(filepath4);
	textures_faces.push_back(filepath5);
	textures_faces.push_back(filepath6);


	glGenTextures(1, &m_Texture3D);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_Texture3D);

	for (unsigned int i = 0; i < textures_faces.size(); i++)
	{
		unsigned char* data = stbi_load(textures_faces[i].c_str(), &width, &height, &nrchannel, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << textures_faces[i] << std::endl;
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	
}

Texture3D::~Texture3D() {
	glDeleteTextures(1, &m_Texture3D);
}



