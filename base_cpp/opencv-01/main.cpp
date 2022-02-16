#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;
#include<opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv)
{

		Mat src = imread("C:\\Users\\DELL\\source\\repos\\opencv-01\\data\\space.jpg");
	if (src.empty())
	{
		
			printf("could not load image…\n");
		return -1;
	}
	namedWindow("test opencv setup", 100);
	imshow("“test opencv setup”", src);
	waitKey(0);
	return 0;
}


/***
int main()
{
	// 读入一张图片（poyanghu缩小图）    
	Mat img = imread("../data/space.jpg");
	// 创建一个名为 "图片"窗口    
	namedWindow("图片");
	// 在窗口中显示图片   
	imshow("图片", img);
	// 等待6000 ms后窗口自动关闭    
	waitKey(6000);
	return 0;
}

***/