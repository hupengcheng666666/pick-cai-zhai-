#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;
int main()
{
	Mat dstImage;
	Mat srcImage = imread("1.jpg");
	vector<Mat>channels;
	cvtColor(srcImage, dstImage,CV_RGB2Lab);
	split(dstImage, channels);
	Mat A = channels.at(1);
	Mat B = channels.at(2);
	Mat L = channels.at(0);
	imshow("A", A);
	imwrite("A.jpg", A);
	imshow("L", L);
	imshow("B", B);
	imshow("Lab", dstImage);
	imwrite("Lab.jpg", dstImage);
	waitKey(0);
	return 0;
}