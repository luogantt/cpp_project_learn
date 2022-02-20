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

    void *bufPtr=0;
    int pointNum=30;

    int pointDim=5;
    cout<<"start"<<endl;


    cout<<"file="<<!file<<endl;
    if (!file) {
        cout<<"!file"<<endl;
        return false;
    }
    // get its size:
    file.seekg(0, std::ios::end);
    fileSize = file.tellg();

    //cout<<file[0]<<endl;
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
    /***
    int i=0;
    file.read((char *) &bufPtr, sizeof 10);

    for(i = 0; i <5; i++) // show values read from file
        cout << bufPtr[i] << " ";

    file.close();
    ***/
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