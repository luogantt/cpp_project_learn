#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;




//int  readBinFile(std::string& filename, void*& bufPtr, int& pointNum, int pointDim)

int main()
{
    // open the file:
    std::streampos fileSize;  //实例化fpos用于表示窄向流中的位置。
    std::ifstream file("/home/oem/CLionProjects/untitled/a.bin", std::ios::binary);


    //指向二进制文件内存的头指针
    void *bufPtr=0;
    //每个pillar 的点云数量
    int pointNum=30;

    //点云数据的列数，x,y,z,r,其他
    int pointDim=5;
    cout<<"start"<<endl;


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
    
    bufPtr = malloc(fileSize);
    if(bufPtr == nullptr){
        cout<<"error"<<endl;
        return false;
    }


    // read the data:

    cout<<"read_data"<<endl;
    file.read((char*) bufPtr, fileSize);


    file.close();


    cout<<"size="<<fileSize<<endl;
    
    pointNum = fileSize /sizeof(float) / pointDim;

    cout<<pointNum<<endl;
    if( fileSize /sizeof(float) % pointDim != 0);
       

    return 1;
}
/***
    int main()
    {        int pointNum = 0;
        void *inputPointBuf = nullptr;

        std::string s0("a.bin");}




***/