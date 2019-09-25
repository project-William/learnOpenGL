#pragma once
#include <glad/glad.h>
#include <string>


class Texture
{
public:
	Texture(const std::string& filepath);
	~Texture();

	inline GLuint GetTExture()const { return m_Texture; }

	void UseTexture();


private:
	std::string m_FilePath;
	GLuint m_Texture;
};