#include "Vec3.h"
#include <fstream>
int main() {
	int nx = 200;
	int ny = 100;

	std::ofstream outfile;
	outfile.open("image.ppm");

	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	for (int i = ny - 1; i >= 0; i--) {
		for (int j = 0; j < nx; j++) {
			Vec3<float> vector(float(j) / nx, float(i) / ny, 0.2f);
			int ir = int(255.99*(vector.get_r()));
			int ig = int(255.99*(vector.get_g()));
			int ib = int(255.99*(vector.get_b()));
			outfile << ir << " " << ig << " " << ib << "\n";
		}
	}

	outfile.close();

	return 0;
}