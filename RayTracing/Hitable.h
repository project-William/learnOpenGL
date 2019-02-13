#ifndef _HITABLE_H_
#define _HITABLE_H_
#include "ray.h"
struct hit_record{
    //ray
    float t;
    //hit point position
    Vec3 p;
    //normal vector of hit point
    Vec3 normal;

};


class Hitable{
public:
    virtual bool hit(const ray& r,float t_min,float t_max,hit_record& rec) const =0;
};






#endif
