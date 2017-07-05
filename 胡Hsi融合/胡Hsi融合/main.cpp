#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;


int main()
{
	double alpha = 0.7;
	double beta = 0.2;//1 - alpha;
	Mat merge1, merge2;//, dstImage
	//Mat dstImage;
	//vector<Mat>channels[3];
	Mat H = imread("Hvalue.jpg");
	cout << "H: " << H.channels() << endl;
	//channels.push_back(H);
	//GaussianBlur(H, H, Size(5, 5), 0, 0);
	//channels.at(0) = H;
	Mat S = imread("Svalue.jpg");
	//GaussianBlur(S, S, Size(5, 5), 0, 0);
	//channels.push_back(S);
	//channels.at(1) = S;
	if (!H.data)
		cout << "H ¼ÓÔØÊ§°Ü" << endl;
	if (!S.data)
		cout << "S ¼ÓÔØÊ§°Ü" << endl;
	addWeighted(H, alpha, S, beta, 0.0, merge1);
	imshow("merge1", merge1);
	Mat I = imread("Ivalue.jpg");
	//GaussianBlur(I, I, Size(5, 5), 0, 0);
	//channels.push_back(I);
	//channels.at(2) = I;
	if (!I.data)
		cout << "I ¼ÓÔØÊ§°Ü" << endl;
	alpha = 0.9;
	beta = 0.1;
	addWeighted(merge1, alpha, I, beta, 0.0, merge2);
	//merge(channels, dstImage);
	//imshow("R", dstImage);
	//×ÔÊÊÓ¦ãÐÖµ
	/*cvtColor(merge2, merge2, CV_RGB2GRAY);
	int blockSize = 5;
	int constValue = 10;
	const int maxValue = 255;
	int adaptiveMethod = 0;
	int thresholdType = 1;
	adaptiveThreshold(merge2, merge2, maxValue, adaptiveMethod, thresholdType, blockSize, constValue);*/
	Mat dstImage;

	dstImage = H&S&I;
	imshow("ÓëÔËËã", dstImage);
	//ÐÎÌ¬Ñ§±ÕÔËËã
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(7, 7));
	//morphologyEx(dstImage, merge2, MORPH_TOPHAT, element);
	morphologyEx(dstImage, merge2, MORPH_CLOSE , element);
	//ÅòÕÍ²Ù×÷
	Mat dilateMat;
	dilate(dstImage, dilateMat, element);
	//imshow("dst", dstImage);
	imwrite("dst.jpg", dstImage);
	

	imshow("ÅòÕÍ", dilateMat);
	cout << "S: " << S.channels() << endl;
	cout << "I: " << I.channels() << endl;
	cout << "merge2: " << merge2.channels() << endl;
	cout << "merge1: " << merge1.channels() << endl;
	imshow("±ÕÔËËã", merge2);
	waitKey(0);
	return 0;


}