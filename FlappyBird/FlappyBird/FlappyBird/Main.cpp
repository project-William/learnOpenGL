#include "src/Application.h"
using namespace flappy::math;

int main() {
	Vec2 vector( 0.0f, 1.0f);
	Vec2 vector1(1.0f, 0.0f);
	float f = getDegrees(vector,vector1);
	std::cout << f << std::endl;
	std::cout << vector.get_x() << "," << vector.get_y() << std::endl;


	return 0;
}