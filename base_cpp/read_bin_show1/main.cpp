#include <math.h>
#include <fstream>
#include <iostream>


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>





//int  readBinFile(std::string& filename, void*& bufPtr, int& pointNum, int pointDim)

int main()
{
    // open the file:
    

    std::streampos fileSize;  //实例化fpos用于表示窄向流中的位置。
    std::ifstream file("../cloud.bin", std::ios::binary);




    cout<<"file="<<!file<<endl;
    if (!file) {
        cout<<"!file"<<endl;
        return false;
    }
    // get its size:

    //把文件的读指针结尾位置向后移前个字节
    file.seekg(0, std::ios::end);
    fileSize = file.tellg();

    //把文件的写指针从文件开头向后移 0 个字节
    file.seekg(0, std::ios::beg);


    cout<<fileSize<<endl;



    //int length=fileSize;
    int length=30;
    double* f2 = new double[length];
    
    struct timeval t_start, t_end;
    gettimeofday(&t_start,NULL);
    std::ifstream ifs("../cloud.bin", std::ios::binary | std::ios::in);
    
    gettimeofday(&t_end,NULL);
    printf("cost time %ldus\n", t_end.tv_usec - t_start.tv_usec);
    ifs.read((char*)f2, sizeof(double) * length);
    ifs.close();

    cout<<f2<<endl;

    for (int i = 0; i < length; i++)
    {
        std::cout<<f2[i]<<std::endl;
    }

    return 0;

    

}
    // read the data:








