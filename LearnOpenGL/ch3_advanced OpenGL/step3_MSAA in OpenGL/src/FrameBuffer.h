#pragma once
#include <glad/glad.h>

class FrameBuffer {
private:
	unsigned int m_FrameBuffer;
	unsigned int m_TextureColorBuffer;
	unsigned int m_RenderBufferObj;
public:
	FrameBuffer(int width, int height);
	~FrameBuffer();

	void bindFramebuffer()const;
	void unbindFramebuffer()const;
	void bindTextureBuffer()const;
	void unbindTextureBuffer()const;
	void bindRenderBuffer()const;
	void unbindRenderBuffer()const;
	void unbindAll()const;

	void genTexture(unsigned int buffer, int width, int height);
	void renderBufferObj(unsigned int rbo, int width, int height);
};