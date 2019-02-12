#include <fstream>
#include "HitableList.h"
#include "sphere.h"
#include <vector>



Vec3 color(ray& r,Hitable* world) {

	//rendering the sphere
	hit_record rec;
	if (world->hit(r, 0.0f, FLT_MAX, rec)) {
		return 0.5f*Vec3(rec.normal.get_x()+1.0f, rec.normal.get_y()+1.0f, rec.normal.get_z()+1.0f);
	}
	else {
		//rendering the background
		Vec3 unit_direction = r.direction().normalize();
		float t = 0.5f*(unit_direction.get_y() + 1.0f);
		return (1.0f - t)*Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
	}
	
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

	Hitable* list[2];
	list[0] = new Sphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f);
	list[1] = new Sphere(Vec3(0.0f, -100.4f, -1.0f), 100.0f);
	Hitable* world = new HitableList(list, 2);


	for (int i = ny - 1; i >= 0; i--) {
		for (int j = 0; j < nx; j++) {
			float u = (float)(j) / (float)(nx);
			float v = (float)(i) / (float)(ny);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			Vec3 p = r.point_on_ray(2.0f);
			Vec3 col = color(r, world);
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