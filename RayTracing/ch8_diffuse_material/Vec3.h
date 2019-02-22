
#pragma once
#include <iostream>
#include <cmath>
class Vec3{
private:
    float x,y,z;
public:
    Vec3(){x=y=z=0;}
    Vec3(float xvalue,float yvalue,float zvalue) {x=xvalue,y=yvalue,z=zvalue;}
    Vec3(float value){x=y=z=value;}
    //get and reset
    inline void reset(float re_x,float re_y,float re_z){x=re_x,y=re_y,z=re_z;}

    inline float get_x()const {return x;}
    inline float get_y()const {return y;}
    inline float get_z()const {return z;}

    inline void addx(float dx){x+=dx;}
    inline void addy(float dy){y+=dy;}
    inline void addz(float dz){z+=dz;}

    inline void subsx(float dx){x-=dx;}
    inline void subsy(float dy){y-=dy;}
    inline void subsz(float dz){z-=dz;}

    inline float magnitude(){return sqrt(x*x+y*y+z*z);}


    //overload operators
    inline Vec3& operator+=(const Vec3& other){
            x+=other.x;
            y+=other.y;
            z+=other.z;
            return *this;
    }

    inline Vec3& operator-=(const Vec3& other){
            x-=other.x;
            y-=other.y;
            z-=other.z;
            return *this;
    }

    inline Vec3& operator*=(const Vec3& other){
            x*=other.x;
            y*=other.y;
            z*=other.z;
            return *this;
    }

    inline Vec3& operator/=(const float t){
            x/=t;
            y/=t;
            z/=t;
            return *this;
    }

    inline void display() const {std::cout<<"X:"<<x<<" Y:"<<y<<" Z:"<<z<<std::endl;}
    inline Vec3& normalise() {
        float t=sqrt(x*x+y*y+z*z);
        x/=t;
        y/=t;
        z/=t;
        return *this;
    }
public:
    friend inline Vec3 Scale_multi(float t,const Vec3& v);
    friend inline Vec3 Scale_divide(float t,const Vec3& v);
    friend inline Vec3 operator+(const Vec3& v1,const Vec3& v2);
    friend inline Vec3 operator-(const Vec3& v1,const Vec3& v2);
    friend inline Vec3 operator*(const Vec3& v1,const Vec3& v2);
    friend inline Vec3 operator/(const Vec3& v1,const Vec3& v2);

    friend inline Vec3 operator*(float t,const Vec3& v);
    friend inline Vec3 operator*(const Vec3& v,float t);
    friend inline Vec3 operator/(const Vec3& v,float t);

    friend inline Vec3 normalise(const Vec3& v);

    friend inline float dot(const Vec3& v1,const Vec3& v2);
    friend inline Vec3 cross(const Vec3& v1,const Vec3& v2);
};

inline Vec3 Scale_multi(float t,const Vec3& v){
    return Vec3(t*v.x,t*v.y,t*v.z);
}

inline Vec3 Scale_divide(float t,const Vec3& v){
    return Vec3(1/t*v.x,1/t*v.y,1/t*v.z);
}

inline Vec3 operator+(const Vec3& v1,const Vec3& v2){
    return Vec3(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
}

inline Vec3 operator-(const Vec3& v1,const Vec3& v2){
    return Vec3(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}

inline Vec3 operator*(const Vec3& v1,const Vec3& v2){
    return Vec3(v1.x*v2.x,v1.y*v2.y,v1.z*v2.z);
}

inline Vec3 operator/(const Vec3& v1,const Vec3& v2){
    return Vec3(v1.x/v2.x,v1.y/v2.y,v1.z/v2.z);
}

inline Vec3 operator*(float t,const Vec3& v){
    return Vec3(t*v.x,t*v.y,t*v.z);
}

inline Vec3 operator*(const Vec3& v,float t){
    return Vec3(v.x*t,v.y*t,v.z*t);
}

inline Vec3 operator/(const Vec3& v,float t){
    return Vec3(v.x/t,v.y/t,v.z/t);
}

inline Vec3 normalise(const Vec3& v){
    float t=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
    return Vec3(v.x/t,v.y/t,v.z/t);
}

inline float dot(const Vec3& v1,const Vec3& v2){
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

inline Vec3 cross(const Vec3& v1,const Vec3& v2){
    return Vec3(
        v1.y*v2.z-v1.z*v2.y,
       -(v1.x*v2.z-v1.z*v2.x),
        v1.y*v2.z-v1.z*v2.y
    );
}

