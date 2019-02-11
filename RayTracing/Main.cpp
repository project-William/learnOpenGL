#include "Vec3.h"
#include <fstream>
#include "Ray.h"

bool hit_sphere(const Vec3& center, float radius, const ray& r) {
	Vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2 * dot(r.direction(), oc);
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a*c;
	return discriminant > 0;
}





Vec3 color(const ray& r) {
	if (hit_sphere(Vec3(0, 0, -1), 0.5, r))
		return Vec3(1, 0, 0);
	Vec3 unit_direction = r.direction().normalize();
	float t = 0.5f*(unit_direction.get_y() + 1.0f);
	return (1.0f - t)*Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}



int main() {
	int nx = 200;
	int ny = 100;

	std::ofstream outfile;
	outfile.open("image.ppm");

	outfile << "P3\n" << nx << " " << ny << "\n255\n";
	Vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	Vec3 horizontal(4.0f, 0.0f, 0.0f);
	Vec3 vertical(0.0f, 2.0f, 0.0f);
	Vec3 origin(0.0f, 0.0f, 0.0f);
	for (int i = ny - 1; i >= 0; i--) {
		for (int j = 0; j < nx; j++) {
			float u = (float)(j) / (float)(nx);
			float v = (float)(i) / (float)(ny);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			Vec3 col = color(r);
			int ir = int(255.99*col.get_r());
			int ig = int(255.99*col.get_g());
			int ib = int(255.99*col.get_b());
			std::cout << ir << " " << ig << " " << ib << "\n";
			outfile << ir << " " << ig << " " << ib << "\n";
		}
	}

	outfile.close();
	system("PAUSE");
	return 0;
}