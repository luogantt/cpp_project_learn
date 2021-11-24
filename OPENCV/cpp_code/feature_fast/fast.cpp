#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
 
#include <vector>
 
using namespace cv;
 
int  main()
{
	Mat image;
	image = imread("church.jpeg");
	// vector of keyPoints
	std::vector<KeyPoint> keyPoints;
	// construction of the fast feature detector object
	FastFeatureDetector fast(40);	// 检测的阈值为40
	// feature point detection
	fast.detect(image,keyPoints);
	drawKeypoints(image, keyPoints, image, Scalar::all(255), DrawMatchesFlags::DRAW_OVER_OUTIMG);
	imshow("FAST feature", image);
	cvWaitKey(0);
	return 0;
}
