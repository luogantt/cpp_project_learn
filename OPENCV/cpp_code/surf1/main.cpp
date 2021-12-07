#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include<iostream>
#include<math.h>
#include <string>
#include<fstream>
using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;

Mat src, graysrc;
int minHesssian = 100;
int maxhessian = 500;

void Surf(int, void*) {

	
    // Ptr<SIFT> detector = SIFT::create(minHesssian);　//SIFT算法
    //Ptr<KAZE> detector = KAZE::create(minHesssian); 
    //Ptr<VGG> detector = VGG_120::create(minHesssian);  //ORB算法
    //Ptr<ORB> detector = ORB::create(minHesssian);  //ORB算法
    Ptr<SURF> detector = SURF::create(minHesssian);// SURF特征检测类，Ptr 智能指针
    vector<KeyPoint>keypoint;//特征点
    detector->detect(src,keypoint);//特征检测
    cout << "keypoint_size=" << keypoint.size() << endl;

    Mat dst;
    drawKeypoints(src, keypoint, dst, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
    cv::imwrite("out.jpg", dst);
    imshow("output", dst);
}

int main() {
    src = imread("/home/ledi/视频/lena.png");
    imshow("input", src);
    //cvtColor(src, graysrc, CV_BGR2GRAY);
    Surf(0, 0);
    createTrackbar("yuzhi", "output", &minHesssian, maxhessian, Surf);
    waitKey(0);
}

