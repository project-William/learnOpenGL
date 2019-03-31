#include "Coordinate.h"



Coordinate::Coordinate(int m_Width,int m_Height)
{
	model = glm::rotate(model, (float)glfwGetTime()*glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)m_Width / (float)m_Height, 0.01f, 100.0f);


}


Coordinate::~Coordinate()
{
}
