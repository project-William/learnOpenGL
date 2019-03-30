#pragma once
#include <glad/glad.h>
#include <string>

class Texture {
private:
	unsigned int m_Texture;
	unsigned char* m_LocalBuffer;
	int width, height, nrchannel;
public:
	Texture(const std::string& filepath);
	~Texture();
	
	void bind(unsigned int slot)const;
	void unbind()const;

	inline int GetTexWidth()const { return width; }
	inline int GetTexHeight()const { return height; }
};