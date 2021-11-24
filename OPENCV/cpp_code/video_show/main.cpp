#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;


int main()
{
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    Mat edges;

    bool stop = false;
    while(!stop)
    {
        cap>>frame;
        cvtColor(frame, edges, CV_BGR2GRAY);
//        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);  
//        Canny(edges, edges, 0, 30, 3);  
        imshow("当前视频",frame);
        if(waitKey(30) >=0)
            stop = true;
    }
    return 0;
}


