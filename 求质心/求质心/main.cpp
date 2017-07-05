//http://blog.csdn.net/zhuoyueljl/article/details/53588271
#include "centroid.h"
//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace std;
//using namespace cv;


Mat src;
//Mat src_gray;
//int thresh = 30;
//int max_thresh = 255;
//double area;

int main()
{
	src = imread("closeMat.jpg");
	Point* A = centroid(src);
	//cout << A << endl;

	/*cvtColor(src,src_gray,CV_BGR2GRAY);
	GaussianBlur(src, src, Size(3, 3), 0.1, 0, BORDER_DEFAULT);
	blur(src_gray,src_gray,Size(3,3));
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", src);
	moveWindow("image", 20, 20);*/
	//定义Canny边缘检测图像
	//Mat canny_output;
	//vector<vector<Point>>contours;
	//vector<Vec4i>hierarchy;
	////利用canny算法检测边缘
	//Canny(src, canny_output, thresh, thresh * 3, 3);
	//namedWindow("canny", CV_WINDOW_AUTOSIZE);
	//imshow("canny", canny_output);
	//moveWindow("canny", 550, 20);
	////查找轮廓
	//findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	////计算轮廓矩
	//vector<Moments>mu(contours.size());
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	mu[i] = moments(contours[i], false);
	//}
	////计算轮廓的质心
	//vector<Point2f>mc(contours.size());
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	mc[i] = Point2d(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);

	//}
	//
	////画轮廓及其质心并显示
	//Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	//char tam[100];
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	Scalar color = Scalar(255, 0, 0);
	//	drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	//	circle(drawing, mc[i], 5, Scalar(0, 0, 255), -1, 8, 0);
	//	rectangle(drawing, boundingRect(contours.at(i)), Scalar(0, 255, 0));
	//	
	//	//计算矩阵面积
	//    area = contourArea(contours.at(i));
	//	if (area > 9000.0)
	//	{
	//		cout << area << endl;
	//		sprintf(tam, "(%0.0f,%0.0f)", mc[i].x, mc[i].y);
	//		putText(drawing, tam, Point(mc[i].x, mc[i].y), FONT_HERSHEY_SIMPLEX, 0.4, Scalar(255, 0, 255), 1);
	//		cout << Point(mc[i].x, mc[i].y) << endl;
	//	}
	//}

	//namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	//imshow("Contours", drawing);
	//moveWindow("Contours", 1100, 20);
	waitKey(0);
	//src.release();
	//src_gray.release();
	return 0;



}