#pragma once
#include "Hitable.h"

/*
determine whether all of the objects would be hit by ray & determine just once a time
if the object be hit by ray the info. of hit would be stored in the struct hit_record
so we can find that ec would be rewrited for times,so the last info. would be stored
(the most effective info. is the last one which is the closest hit point to observation)
for no matter how many objects the ray hits and how many hit points it produced,we need
the closest point to our observation,if the hit point is in the range,the distance of 
this hit point would be set as the largest value of range.
*/

class HitableList :public Hitable {
public:
	HitableList(){}
	HitableList(Hitable** l, int n) { list = l, list_size = n; }
	virtual bool hit(ray& r, float tmin, float tmax, hit_record& rec)const;

public:
	Hitable** list;
	int list_size;
};

bool HitableList::hit(ray& r, float tmin, float tmax, hit_record& rec)const {
	hit_record temp_rec;
	bool hit_anything = false;
	double closes_so_far = tmax;

	for (int i = 0; i < list_size; i++) {
		if (list[i]->hit(r, tmin, closes_so_far, temp_rec)) {
			hit_anything = true;
			closes_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}




