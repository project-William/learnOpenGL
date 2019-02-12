#pragma once
#include "Ray.h"


//ray hit record
struct hit_record
{
	//ray parameter
	float t;
	//hit position vector
	Vec3 p;
	//normal vector of hit position
	Vec3 normal;

};

class Hitable {
public:
	virtual bool hit(ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};







