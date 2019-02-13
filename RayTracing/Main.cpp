#include "vec3.h"
#include <fstream>
#include "ray.h"
#include "sphere.h"
#include "HitableList.h"
#include "float.h"



Vec3 color(const ray& r,Hitable* world){
    //sphere
    hit_record rec;
    if(world->hit(r,0.0f,FLT_MAX,rec)){
        return 0.5f*(Vec3(rec.normal.getx(),rec.normal.gety(),rec.normal.getz())+Vec3(1.0f,1.0f,1.0f));
    }
    //background
    Vec3 unit_direction=r.direction().normalise();
    float k=0.5f*(unit_direction.gety()+1.0f);
    return (1.0f-k)*Vec3(1.0f,1.0f,1.0f)+k*Vec3(0.0f,0.2f,1.0f);

}

int main(){
    std::ofstream outfile;
    outfile.open("fuck.ppm");

    int nx=200;
    int ny=100;

    outfile<<"P3\n"<<nx<<"  "<<ny<<"\n255\n";

    Vec3 lower_left_coner(-2.0f,-1.0f,-1.0f);
    Vec3 horizontal(4.0f,0.0f,0.0f);
    Vec3 vertical(0.0f,2.0f,0.0f);
    Vec3 origin(0.0f,0.0f,0.0f);


    Hitable* list[2];
    list[0]=new Sphere(Vec3(0.0f,0.0f,-1.0f),0.5f);
    list[1]=new Sphere(Vec3(0.0f,-100.5f,-1.0f),100.0f);
    Hitable* world=new HitableList(list,2);

    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){
            float u=(float)(j)/(float)(nx);
            float v=(float)(i)/(float)(ny);
            ray r(origin,lower_left_coner+u*horizontal+v*vertical);

            Vec3 p=r.point_on_ray(2.0f);
            Vec3 col=color(r,world);
            int value_r=(int)(255.99*col.getx());
            int value_g=(int)(255.99*col.gety());
            int value_b=(int)(255.99*col.getz());


            outfile<<value_r<<" "<<value_g<<" "<<value_b<<"\n";
        }
    }

    outfile.close();
    return 0;
}
