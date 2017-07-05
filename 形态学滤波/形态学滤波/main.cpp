#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImage = imread("A.jpg");
	imshow("src", srcImage);
	Mat dstImage;
	//��̬ѧ������
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
	morphologyEx(srcImage, dstImage, MORPH_CLOSE, element);
	//��̬ѧ�ݶ�
	Mat ele = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dst;
	morphologyEx(dstImage, dst, MORPH_GRADIENT, ele);
	//��ñ
	Mat Image;
	morphologyEx(srcImage, Image, MORPH_TOPHAT, element);
	//��ñ
	Mat d;
	morphologyEx(srcImage, d, MORPH_BLACKHAT, element);
	//��ֵ�˲�
	Mat z;
	medianBlur(srcImage, z, 3);

	imwrite("Z.jpg", z);
	imwrite("close.jpg", dstImage);
	imshow("z", z);
	imshow("B", d);
	imshow("TOPHAT", Image);
	imshow("�ݶ�", dst);
	imshow("close", dstImage);
	waitKey(0);
	return 0;
}