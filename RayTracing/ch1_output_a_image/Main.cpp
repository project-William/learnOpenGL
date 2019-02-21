#include <iostream>
#include <fstream>

int main(){
    std::ofstream outfile;
    outfile.open("first_image.ppm");

    int nx=200,ny=100;

    outfile<<"P3\n"<<nx<<" "<<ny<<"\n255\n";

    for(int i=ny-1;i>=0;i--){
        for(int j=0;j<nx;j++){
            float r=(float)j/nx;
            float g=(float)i/ny;
            float b=0.4f;

            int ir=(int)(255.99*r);
            int ig=(int)(255.99*g);
            int ib=(int)(255.99*b);

            outfile<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    outfile.close();

    return 0;

}
