//#include<opencv2/opencv.hpp>
//#include<math.h>
//#include<vector>
#include "HSI.h"
//using namespace std;
//using namespace cv;

//-------------------------- RGB 模型 转换为 HSI 模型--------------------//
int main() {
	Mat BGRImage = imread("1.jpg");
	imshow("RGB",BGRImage);
	Mat H, S, I,HSI;
	BGRtoHSI(BGRImage, H, S, I,HSI);
	imshow("H", H);
	imshow("S", S);
	imshow("I", I);
	imwrite("H.jpg", H);
	imwrite("S.jpg", S);
	imwrite("I.jpg", I);
	imshow("HSI", HSI);
	imwrite("HSI.jpg", HSI);
	//Mat HSIImage = Mat(Size(BGRImage.cols, BGRImage.rows), CV_8UC3);

	//vector <Mat> channels;
	//split(HSIImage, channels);
	//Mat Hvalue = channels.at(0);
	//Mat Svalue = channels.at(1);
	//Mat Ivalue = channels.at(2);

	//for (int i = 0; i < BGRImage.rows; ++i)
	//	for (int j = 0; j < BGRImage.cols; ++j)
	//	{
	//		double H, S, I;
	//		int Bvalue = BGRImage.at<Vec3b>(i, j)(0);
	//		int Gvalue = BGRImage.at<Vec3b>(i, j)(1);
	//		int Rvalue = BGRImage.at<Vec3b>(i, j)(2);

	//		//求Theta =acos((((Rvalue - Gvalue) + (Rvalue - Bvalue)) / 2) / sqrt(pow((Rvalue - Gvalue), 2) + (Rvalue - Bvalue)*(Gvalue - Bvalue)));
	//		double numerator = ((Rvalue - Gvalue) + (Rvalue - Bvalue)) / 2;
	//		double denominator = sqrt(pow((Rvalue - Gvalue), 2) + (Rvalue - Bvalue)*(Gvalue - Bvalue));
	//		if (denominator == 0) H = 0;
	//		else {
	//			double Theta = acos(numerator / denominator) * 180 / 3.14;
	//			if (Bvalue <= Gvalue)
	//				H = Theta;
	//			else  H = 360 - Theta;
	//		}
	//		Hvalue.at<uchar>(i, j) = (int)(H * 255 / 360); //为了显示将[0~360]映射到[0~255]

	//													   //求S = 1-3*min(Bvalue,Gvalue,Rvalue)/(Rvalue+Gvalue+Bvalue);
	//		int minvalue = Bvalue;
	//		if (minvalue > Gvalue) minvalue = Gvalue;
	//		if (minvalue > Rvalue) minvalue = Rvalue;
	//		numerator = 3 * minvalue;
	//		denominator = Rvalue + Gvalue + Bvalue;
	//		if (denominator == 0)  S = 0;
	//		else {
	//			S = 1 - numerator / denominator;
	//		}
	//		Svalue.at<uchar>(i, j) = (int)(S * 255);//为了显示将[0~1]映射到[0~255]

	//		I = (Rvalue + Gvalue + Bvalue) / 3;
	//		Ivalue.at<uchar>(i, j) = (int)(I);
	//	}

	//merge(channels, HSIImage);
	//namedWindow("HSI");
	//imshow("HSI", HSIImage);
	//imshow("H", Hvalue);
	//imshow("S", Svalue);
	//imshow("I", Ivalue);
	waitKey(0);
	return 0;
}
//http://blog.csdn.net/nanami809/article/details/50212789