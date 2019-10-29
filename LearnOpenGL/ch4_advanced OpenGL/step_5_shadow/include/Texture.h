#pragma once
#include <glad/glad.h>
#include <string>


class Texture
{
public:
	Texture();
	Texture(const std::string& filepath);
	~Texture();

	int GetTexWidth()const { return m_Width; }
	int GetTexHeight()const { return m_Height; }

	GLuint GetTExture()const { return m_Texture; }

	void UseTexture(int index);
	void GenerateDepthMap();

private:
	std::string m_FilePath;
	GLuint m_Texture;

	int m_Width;
	int m_Height;
	int m_Channels;

};