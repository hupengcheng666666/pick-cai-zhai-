#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage = imread("A.jpg");
	imshow("src", srcImage);
	Mat dstImage;
	//形态学闭运算
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
	morphologyEx(srcImage, dstImage, MORPH_CLOSE, element);
	//形态学梯度
	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dst;
	morphologyEx(dstImage, dst, MORPH_GRADIENT, ele);
	//顶帽
	Mat Image;
	morphologyEx(srcImage, Image, MORPH_TOPHAT, element);
	//底帽
	Mat d;
	morphologyEx(srcImage, d, MORPH_BLACKHAT, element);
	//中值滤波
	Mat z;
	medianBlur(srcImage, z, 3);

	imwrite("Z.jpg", z);
	imwrite("close.jpg", dstImage);
	imshow("z", z);
	imshow("B", d);
	imshow("TOPHAT", Image);
	imshow("梯度", dst);
	imshow("close", dstImage);
	waitKey(0);
	return 0;
}