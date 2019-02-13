#ifndef _RAY_H_
#define _RAY_H_
#include "vec3.h"

class ray{
private:
    Vec3 A,B;
public:
    ray(const Vec3& a,const Vec3& b){A=a,B=b;}
    Vec3 origin() const {return A;}
    Vec3 direction() const {return B;}
    Vec3 point_on_ray(float t)const {return A+t*B;}

};




#endif // _RAY_H_
