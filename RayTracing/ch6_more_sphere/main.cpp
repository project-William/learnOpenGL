#include <fstream>
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "float.h"

Vec3 Color(const Ray& r,Hitable* world){
    hit_record rec;
    if(world->hit(r,0.0f,FLT_MAX,rec))
        return 0.5f*(Vec3(rec.normal.get_x(),rec.normal.get_y(),rec.normal.get_z())+Vec3(1.0f));

    Vec3 unit_direction=normalise(r.direction());
    float t=0.5f*(unit_direction.get_y()+1.0f);
    return (1-t)*Vec3(1.0f)+t*Vec3(0.5f,0.8f,1.0f);
}



int main(){
    std::ofstream outfile;
    outfile.open("sixth_image.ppm");

    int nx=200,ny=100;

    outfile<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    Vec3 lower_left_corner(-2.0f,-1.0f,-1.0f);
    Vec3 origin(0.0f);
    Vec3 horizontal(4.0f,0.0f,0.0f);
    Vec3 vertical(0.0f,2.0f,0.0f);

    Hitable* list[2];
    list[0]=new Sphere(Vec3(0.0f,0.0f,-1.0f),0.5f);
    list[1]=new Sphere(Vec3(0.5f,-100.5f,-1.0f),100.0f);
    Hitable* world=new HitableList(list,2);

    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){
            float u=(float)j/nx;
            float v=(float)i/ny;
            Ray r(origin,lower_left_corner+u*horizontal+v*vertical);

            Vec3 p=r.point_on_ray(2.0f);
            Vec3 col=Color(r,world);

            int ir=(int)(255.99*col.get_x());
            int ig=(int)(255.99*col.get_y());
            int ib=(int)(255.99*col.get_z());

            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    outfile.close();

    return 0;

}
