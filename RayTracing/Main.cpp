#include <random>
#include <fstream>
#include "sphere.h"
#include "HitableList.h"
#include "float.h"
#include "Camera.h"


Vec3 Color(const Ray& r,Hitable* world){
    //sphere
    hit_record rec;
    if(world->hit(r,0.0f,FLT_MAX,rec)){
        return 0.5f*(Vec3(rec.normal.get_x(),rec.normal.get_y(),rec.normal.get_z())+Vec3(1.0f,1.0f,1.0f));
    }
    //background
    Vec3 unit_direction=r.direction().normalise();
    float k=0.5f*(unit_direction.get_y()+1.0f);
    return (1.0f-k)*Vec3(1.0f,1.0f,1.0f)+k*Vec3(0.0f,0.2f,1.0f);

}

int main(){
    std::ofstream outfile;
    outfile.open("fuck.ppm");

    int nx=200;
    int ny=100;

    int ns=100;
    outfile<<"P3\n"<<nx<<"  "<<ny<<"\n255\n";

    Hitable* list[2];
    list[0]=new Sphere(Vec3(0.0f,0.0f,-1.0f),0.5f);
    list[1]=new Sphere(Vec3(0.5f,0.5f,-1.5f),0.5f);
    Hitable* world=new HitableList(list,2);

    Camera cam;

    std::default_random_engine reng;
    std::uniform_real_distribution<float> dis(0.0f,1.0f);


    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){

            Vec3 col;

            for(int s=0;s<ns;s++){
                float u=(float)(j+dis(reng))/(float)(nx);
                float v=(float)(i+dis(reng))/(float)(ny);
                Ray r=cam.getRay(u,v);
                col+=Color(r,world);
            }

            col/=float(ns);
            int value_r=(int)(255.99*col.get_x());
            int value_g=(int)(255.99*col.get_y());
            int value_b=(int)(255.99*col.get_z());


            outfile<<value_r<<" "<<value_g<<" "<<value_b<<"\n";
        }
    }

    outfile.close();
    return 0;
}
