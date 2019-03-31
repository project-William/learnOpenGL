#include "Transformation.h"


void Transformation::Translate(float x,float y,float z) {
	trans = glm::translate(trans, glm::vec3(x, y, z));
}


void Transformation::Rotate(float angle,float x,float y, float z) {
	trans = glm::rotate(trans, glm::radians(angle), glm::vec3(x, y, z));
}

void Transformation::Scale(float x, float y, float z) {
	trans = glm::scale(trans, glm::vec3(x, y, z));
}