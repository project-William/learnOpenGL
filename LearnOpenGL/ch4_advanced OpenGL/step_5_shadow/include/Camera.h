#pragma once
#include <glm/glm.hpp>	
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	


struct CameraAttrib
{
	glm::vec3 FocusPoint = glm::vec3(0.0f);
	glm::vec3 Position=glm::vec3(3.0f, 3.0f, -3.0f);
	glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Front = glm::normalize(Position - FocusPoint);
	glm::vec3 Right = glm::vec3(0.0f);
	float Yaw = 0.0f;
	float Pitch = 0.0f;
};


class Camera
{
public:
	Camera(glm::vec3 position);
	~Camera();


	glm::mat4 GetViewMatrix();

	void Update();

private:
	CameraAttrib m_CamAttrib;


};