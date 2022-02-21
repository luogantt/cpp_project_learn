#include <math.h>
#include <fstream>
#include <iostream>
int main(){

    /***
    const int length = 100;
    double f1[length] ;
    for (int i = 0; i < length; i++)
    {
        f1[i] = i + i / 1000.0;
    }
    std::ofstream  ofs("1.txt", std::ios::binary | std::ios::out);
    ofs.write((const char*)f1, sizeof(double) * length);
    ofs.close();
    ***/
    int length = 1000;
    double* f2 = new double[length];
    std::ifstream ifs("a.bin", std::ios::binary | std::ios::in);
    ifs.read((char*)f2, sizeof(double) * length);
    ifs.close();

    for (int i = 0; i < length; i++)
    {
        std::cout<<f2[i]<<std::endl;
    }
    return 0;
}
