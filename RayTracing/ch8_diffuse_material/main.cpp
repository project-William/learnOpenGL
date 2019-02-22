#include <fstream>
#include <random>
#include "Sphere.h"
#include "HitableList.h"
#include "float.h"
#include "Camera.h"

Vec3 RandomOnSurfaceSphere(){
    Vec3 p;
    do{
        p=2.0f*(Vec3(rand()%100/(float)100,rand()%100/(float)100,rand()%100/(float)100)-Vec3(1.0f));
    }while(dot(p,p)>=1.0f);
    return p;
}

Vec3 Color(const Ray& r,Hitable* world){
    hit_record rec;
    if(world->hit(r,0.0f,FLT_MAX,rec)){
        Vec3 target=rec.p+rec.normal+RandomOnSurfaceSphere();
        return 0.5f*Color(Ray(rec.p,target-rec.p),world);
    }

    Vec3 unit_direction=normalise(r.direction());
    float t=0.5f*(unit_direction.get_y()+1.0f);
    return (1-t)*Vec3(1.0f)+t*Vec3(0.5f,0.8f,1.0f);
}



int main(){
    std::ofstream outfile;
    outfile.open("seventh_image.ppm");

    int nx=1800,ny=900;

    int ns=100;

    outfile<<"P3\n"<<nx<<" "<<ny<<"\n255\n";

    std::default_random_engine random;
    std::uniform_real_distribution<float> dis(0.0f,1.0f);

    Hitable* list[2];
    list[0]=new Sphere(Vec3(0.0f,0.0f,-1.0f),0.5f);
    list[1]=new Sphere(Vec3(0.5f,-100.5f,-1.0f),100.0f);
    Hitable* world=new HitableList(list,2);

    Camera cam;

    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){
            Vec3 col;

            for(int s=0;s<ns;s++){
                float u=(float)(j+dis(random))/nx;
                float v=(float)(i+dis(random))/ny;
                Ray r=cam.getRay(u,v);
                col+=Color(r,world);
            }

            col/=float(ns);
            col=Vec3(sqrt(col.get_x()),sqrt(col.get_y()),sqrt(col.get_z()));

            int ir=(int)(255.99*col.get_x());
            int ig=(int)(255.99*col.get_y());
            int ib=(int)(255.99*col.get_z());

            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    outfile.close();

    return 0;

}
