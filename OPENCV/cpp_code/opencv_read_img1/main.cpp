#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace cv;
using namespace std;
 
int main(void)
{
 
 
        Mat image = imread("../hani.jpeg"); 
 
        //MAT是数据类型（主要用来保存图片信息），image是变量名称。
 
        imshow("窗口名称",image);     //image在这个窗口上显示.
 
        waitKey(20000);         //等待KEY,2000毫秒，2s等待输入，过了2s自动执行return 0.
 
        return 0;
 
 
}
