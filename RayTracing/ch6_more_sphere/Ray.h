#pragma once
#include "Vec3.h"

class Ray{
public:
    //A:origin B:direction
    Vec3 A,B;
public:
    Ray(){}
    Ray(const Vec3& a,const Vec3& b){A=a,B=b;}

    Vec3 origin()const{return A;}
    Vec3 direction()const {return B;}
    Vec3 point_on_ray(float t)const {return A+t*B;}

};
