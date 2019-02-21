#include <fstream>
#include "Vec3.h"

int main(){
    std::ofstream outfile;
    outfile.open("second_image.ppm");

    int nx=200,ny=100;

    outfile<<"P3\n"<<nx<<" "<<ny<<"\n255\n";

    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){
            Vec3 col((float)i/ny,(float)j/nx,0.4f);

            int ir=(int)(255.99*col.get_x());
            int ig=(int)(255.99*col.get_y());
            int ib=(int)(255.99*col.get_z());

            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    outfile.close();

    return 0;

}
