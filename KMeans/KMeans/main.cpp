//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//using namespace std;
//using namespace cv;
#include "k.h"


int main()
{
	
	Mat img = imread("Lab.jpg");
	imshow("Image", img);
	//Mat A(img.size(), CV_32FC1);
	Mat img1 = myKmeans(img);
	
	////����һάͼ������㣬��������ͼ�����ص㣬ע�������ʽΪ32bit������
	//Mat sample(img.cols*img.rows, 1, CV_32FC3);
	//
	////��Ǿ���32λ����
	//Mat labels(img.cols*img.rows, 1, CV_32SC1);
	//uchar *p;
	//int i, j, k = 0;

	//for (i = 0; i < img.rows; i++)
	//{
	//	p = img.ptr<uchar>(i);

	//	for (j = 0; j < img.cols; j++)
	//	{
	//		sample.at<Vec3f>(k, 0)[0] = float(p[j * 3]);
	//		sample.at<Vec3f>(k, 0)[1] = float(p[j * 3 + 1]);
	//		sample.at<Vec3f>(k, 0)[2] = float(p[j * 3 + 2]);
	//		//A.at<uchar>(i,j)= float(p[j * 3 + 1]);
	//		k++;

	//	}

	//}

	////��Aͨ���˲��������У�
	////vector<Mat>channels;
	//////cvtColor(srcImage, dstImage, CV_RGB2Lab);
	////split(sample, channels);
	////Mat srcImage = channels.at(1);
	////
	//////Mat srcImage = sample.channels[1];
	////Mat sample1;
	////Mat ele = getStructuringElement(MORPH_RECT, Size(3, 3));
	////morphologyEx(srcImage, sample1, MORPH_BLACKHAT, ele);

	//int clusterCount = 2;
	//Mat centers(clusterCount, 1, sample.type());
	//kmeans(sample, clusterCount, labels, 
	//	TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0),
	//	3, KMEANS_PP_CENTERS, centers);


	////������֪���������࣬�ò�ͬ�ĻҶȲ��ʾ
	//Mat img1(img.rows, img.cols, CV_8UC1);
	//float step = 255 / (clusterCount - 1);
	//k = 0;
	//for (i = 0; i < img1.rows; i++)
	//{
	//	p = img1.ptr<uchar>(i);
	//	for (j = 0; j < img1.cols; j++)
	//	{
	//		int tt = labels.at<int>(k, 0);
	//		k++;
	//		p[j] = 255 - tt*step;
	//	}
	//}
	//img1.convertTo(img1, CV_8UC3);
	imshow("Kmeans", img1);
	
	cout << img1.channels() << endl;
	imwrite("img.jpg", img1);
	Mat t = imread("img.jpg");
	Mat img2 = imread("dst.jpg");
	imshow("dstI", img2);
	
	//��ֵ�������������ͼ����lab��ֵ��ͼ����ͬ��
	cout <<"img2: "<< img2.channels() << endl;
	Mat img3 = t | img2;
	imshow("������", img3);
	
	//��ѧ��̬ѧ�ղ���
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(25, 25));
	Mat closedMat;
	morphologyEx(img3, closedMat, MORPH_OPEN, element);
	imshow("������", closedMat);
	imwrite("closeMat.jpg", closedMat);
	waitKey(0);
	return 0;

}