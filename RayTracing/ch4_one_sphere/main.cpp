#include <fstream>
#include "Ray.h"
bool HitSphere(const Ray& r,Vec3 center,float radius){
    Vec3 oc=r.origin()-center;
    float a=dot(r.direction(),r.direction());
    float b=dot(oc,r.direction())*2.0f;
    float c=dot(oc,oc)-radius*radius;
    float discriminant=pow(b,2)-4*a*c;
    return discriminant>0;
}


Vec3 Color(const Ray& r){
    if(HitSphere(r,Vec3(0.0f,0.0f,-1.0f),0.5f))
        return Vec3(1.0f,0.2f,0.2f);
    Vec3 unit_direction=normalise(r.direction());
    float t=0.5f*(unit_direction.get_y()+1.0f);
    return (1-t)*Vec3(1.0f)+t*Vec3(0.3f,0.3f,1.0f);
}



int main(){
    std::ofstream outfile;
    outfile.open("third_image.ppm");

    int nx=200,ny=100;

    outfile<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    Vec3 lower_left_corner(-2.0f,-1.0f,-1.0f);
    Vec3 origin(0.0f);
    Vec3 horizontal(4.0f,0.0f,0.0f);
    Vec3 vertical(0.0f,2.0f,0.0f);

    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){
            float u=(float)j/nx;
            float v=(float)i/ny;
            Ray r(origin,lower_left_corner+u*horizontal+v*vertical);
            Vec3 col=Color(r);

            int ir=(int)(255.99*col.get_x());
            int ig=(int)(255.99*col.get_y());
            int ib=(int)(255.99*col.get_z());

            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    outfile.close();

    return 0;

}
