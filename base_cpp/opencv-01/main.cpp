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
		
			printf("could not load image��\n");
		return -1;
	}
	namedWindow("test opencv setup", 100);
	imshow("��test opencv setup��", src);
	waitKey(0);
	return 0;
}


/***
int main()
{
	// ����һ��ͼƬ��poyanghu��Сͼ��    
	Mat img = imread("../data/space.jpg");
	// ����һ����Ϊ "ͼƬ"����    
	namedWindow("ͼƬ");
	// �ڴ�������ʾͼƬ   
	imshow("ͼƬ", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�    
	waitKey(6000);
	return 0;
}

***/