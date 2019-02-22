#pragma once
#include "Ray.h"
struct hit_record{
    //ray
    float t;
    //position of hit point
    Vec3 p;
    //normal vector
    Vec3 normal;
};

class Hitable{
public:
    virtual bool hit(const Ray& r,float t_min,float t_max,hit_record& rec)const =0;
};
