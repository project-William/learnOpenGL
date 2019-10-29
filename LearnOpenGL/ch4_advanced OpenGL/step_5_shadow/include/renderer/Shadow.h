#pragma once
#include "Common.h"
#include "Texture.h"


class Shader;
class Shadow
{
public:
	Shadow();
	~Shadow();
	
	int GetShadowMapWidth() const { return m_Width; }
	int GetShadowMapHeight() const { return m_Height; }

	void RenderShadow(const glm::vec3& lightPos, Shader& shader, std::function<void()> func);
	glm::mat4 GetLightSpaceMatrix()const { return lightSpaceMatrix; }
	unsigned int GetDepthMapFBO()const { return m_DepthMapFBO; }
	float near_plane = 1.0f, far_plane = 7.5f;

	void Init(unsigned int texture);
private:
	glm::mat4 lightSpaceMatrix;
	unsigned int m_DepthMapFBO;
	int m_Width;
	int m_Height;
};