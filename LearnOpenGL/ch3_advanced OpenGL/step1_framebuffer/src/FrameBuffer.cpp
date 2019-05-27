#include "FrameBuffer.h"
#include <iostream>

FrameBuffer::FrameBuffer(int width,int height)
	:m_FrameBuffer(0),m_RenderBufferObj(0),m_TextureColorBuffer(0)
{
	glGenFramebuffers(1, &m_FrameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);
	genTexture(m_TextureColorBuffer, width, height);
	renderBufferObj(m_RenderBufferObj, width, height);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR: framebuffer: framebuffer is not completed!" << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &m_FrameBuffer);
}

void FrameBuffer::bindFramebuffer() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);
}

void FrameBuffer::unbindFramebuffer() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::bindTextureBuffer() const
{
	glBindTexture(GL_TEXTURE_2D, m_TextureColorBuffer);
}

void FrameBuffer::unbindTextureBuffer() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void FrameBuffer::bindRenderBuffer() const
{
	glBindRenderbuffer(GL_RENDERBUFFER, m_RenderBufferObj);
}

void FrameBuffer::unbindRenderBuffer() const
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void FrameBuffer::unbindAll()const {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void FrameBuffer::genTexture(unsigned int buffer,int width,int height)
{
	glGenTextures(1, &buffer);
	glBindTexture(GL_TEXTURE_2D, buffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, buffer, 0);
}

void FrameBuffer::renderBufferObj(unsigned int rbo,int width,int height)
{
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
}
