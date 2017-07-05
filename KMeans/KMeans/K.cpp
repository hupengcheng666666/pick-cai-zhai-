#include "k.h"
Mat myKmeans(Mat img)
{
	//生成一维图像采样点，包括所有图像像素点，注意采样格式为32bit浮点数
	Mat sample(img.cols*img.rows, 1, CV_32FC3);

	//标记矩阵，32位整形
	Mat labels(img.cols*img.rows, 1, CV_32SC1);
	uchar *p;
	int i, j, k = 0;

	for (i = 0; i < img.rows; i++)
	{
		p = img.ptr<uchar>(i);

		for (j = 0; j < img.cols; j++)
		{
			sample.at<Vec3f>(k, 0)[0] = float(p[j * 3]);
			sample.at<Vec3f>(k, 0)[1] = float(p[j * 3 + 1]);
			sample.at<Vec3f>(k, 0)[2] = float(p[j * 3 + 2]);
			//A.at<uchar>(i,j)= float(p[j * 3 + 1]);
			k++;

		}

	}

	//对A通道滤波（不可行）
	//vector<Mat>channels;
	////cvtColor(srcImage, dstImage, CV_RGB2Lab);
	//split(sample, channels);
	//Mat srcImage = channels.at(1);
	//
	////Mat srcImage = sample.channels[1];
	//Mat sample1;
	//Mat ele = getStructuringElement(MORPH_RECT, Size(3, 3));
	//morphologyEx(srcImage, sample1, MORPH_BLACKHAT, ele);

	int clusterCount = 2;
	Mat centers(clusterCount, 1, sample.type());
	kmeans(sample, clusterCount, labels,
		TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0),
		3, KMEANS_PP_CENTERS, centers);


	//我们已知有两个个聚类，用不同的灰度层表示
	Mat img1(img.rows, img.cols, CV_8UC1);
	float step = 255 / (clusterCount - 1);
	k = 0;
	for (i = 0; i < img1.rows; i++)
	{
		p = img1.ptr<uchar>(i);
		for (j = 0; j < img1.cols; j++)
		{
			int tt = labels.at<int>(k, 0);
			k++;
			p[j] = 255 - tt*step;
		}
	}
	return img1;
}