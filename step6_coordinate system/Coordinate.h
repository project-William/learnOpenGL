#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Coordinate
{
public:
	Coordinate(int m_Width, int m_Height);
	~Coordinate();
public:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
};

