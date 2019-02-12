#pragma once
#include "Hitable.h"

class Sphere :public Hitable {
public:

	Sphere(){}
	Sphere(Vec3 cen, float r) :center(cen), radius(r) {};
	virtual bool hit(ray& r, float tmin, float tmax, hit_record& rec)const;

public:
	Vec3 center;
	float radius;
};


bool Sphere::hit(ray& r, float tmin, float tmax, hit_record& rec) const {
	Vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0f*dot(oc, r.direction());
	float c = dot(oc, oc) + radius * radius;
	float discriminant = b * b - 4.0f*a*c;

	if (discriminant > 0) {
		float temp = (-b - sqrt(discriminant) / (2.0f*a));
		if (temp<tmax&&temp>tmin) {
			rec.t = temp;
			rec.p = r.point_on_ray(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(discriminant) / (2.0f*a));
		if (temp<tmax&&temp>tmin) {
			rec.t = temp;
			rec.p = r.point_on_ray(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	else {
		return false;
	}

}





