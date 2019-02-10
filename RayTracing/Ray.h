#pragma once
#include "Vec3.h"



class ray {
public:
	//origin point of the ray
	Vec3 A;
	//direction point of the ray
	Vec3 B;
	ray(const Vec3& a, const Vec3& b) { A = a, B = b; }
	Vec3 origin() const { return A; }
	Vec3 direction() const { return B; }
	Vec3 point_on_ray(float t) { return A + t * B; }
	
};