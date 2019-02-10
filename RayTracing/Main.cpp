#include "Vec3.h"

int main() {
	Vec3<float> vector1(1.0f,1.0f,1.0f);
	Vec3<float> vector2(1.0f, 2.0f, 2.0f);
	Vec3<float> vector3;
	
	vector2.normalize();

	vector2.display();
	system("PAUSE");
	return 0;
}