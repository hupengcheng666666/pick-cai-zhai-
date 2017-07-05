#include "otsu.h"

Mat OTSU(cv::Mat srcImage)
{
	//灰度转换
	Mat srcGray;
	cvtColor(srcImage, srcGray, CV_RGB2GRAY);
	//imshow("srcGray", srcGray);

	int nCols = srcGray.cols;
	int nRows = srcGray.rows;
	int threshold = 0;

	//初始化统计参数
	int nSumPix[256] = {0};
	float nProDis[256] = {0};
	/*for (int i = 0; i < 256; i++)
	{
		nSumPix[i] = 0;
		nProDis[i] = 0;

	}*/

	//统计灰度图级中每个像素在整幅图像中的个数
	for (int i = 0; i < nCols; i++)
	{
		for (int j = 0; j < nRows; j++)
		{
			nSumPix[(int)srcGray.at<uchar>(j, i)]++;
		}
	}

	//计算每个灰度级占图像中的概率分布
	for (int i = 0; i < 256; i++)
	{
		nProDis[i] = (float)nSumPix[i] / (nCols*nRows);
	}

	//遍历灰度级【0，255】，计算出最大类间方差下的阈值
	float w0, w1, u0_temp, u1_temp, u0, u1, delta_temp;
	double delta_max = 0.0;
	for (int i = 0; i < 256; i++)
	{
		//初始化相关参数
		w0 = w1 = u0_temp = u1_temp = u0 = u1 = delta_temp = 0;
		for (int j = 0; j < 256; j++)
		{
			//背景部分
			if (j <= i)
			{
				//当前i为分割阈值，第一类总的概率
				w0 += nProDis[j];
				u0_temp += j*nProDis[j];
			}
			//前景部分
			else
			{
				//当前i为分割阈值，第一类总的概率
				w1 += nProDis[j];
				u1_temp += j*nProDis[j];
			}
		}
		//分别计算各类的平均灰度
		u0 = u0_temp / w0;
		u1 = u1_temp / w1;
		delta_temp = (float)(w0*w1*pow((u0 - u1), 2));
		//依次找到最大类间方差下的阈值
		if (delta_temp > delta_max)
		{
			delta_max = delta_temp;
			threshold = i;
		}
	}

	cout << threshold << endl;
	//定义输出结果图像
	Mat otsuResultImage = Mat::zeros(srcGray.rows, srcGray.cols, CV_8UC1);
	//利用得到的阈值实现二值化操作
	for (int i = 0; i < srcGray.rows; i++)
	{
		for (int j = 0; j < srcGray.cols; j++)
		{
			if (srcGray.at<uchar>(i, j) > threshold)
			{
				otsuResultImage.at<uchar>(i, j) = 255;
			}
			else
			{
				otsuResultImage.at<uchar>(i, j) = 0;
			}
		}
	}
	return otsuResultImage;
}