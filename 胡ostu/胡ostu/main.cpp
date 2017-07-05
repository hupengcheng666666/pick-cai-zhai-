#include "otsu.h"



//int OTSU(cv::Mat srcImage)
//{
//	int nCols = srcImage.cols;
//	int nRows = srcImage.rows;
//	int threshold = 0;
//
//	//��ʼ��ͳ�Ʋ���
//	int nSumPix[256];
//	float nProDis[256];
//	for (int i = 0; i < 256; i++)
//	{
//		nSumPix[i] = 0;
//		nProDis[i] = 0;
//
//	}
//
//	//ͳ�ƻҶ�ͼ����ÿ������������ͼ���еĸ���
//	for (int i = 0; i < nCols; i++)
//	{
//		for (int j = 0; j < nRows; j++)
//		{
//			nSumPix[(int)srcImage.at<uchar>(j, i)]++;
//		}
//	}
//
//	//����ÿ���Ҷȼ�ռͼ���еĸ��ʷֲ�
//	for (int i = 0; i < 256; i++)
//	{
//		nProDis[i] = (float)nSumPix[i] / (nCols*nRows);
//	}
//
//	//�����Ҷȼ���0��255��������������䷽���µ���ֵ
//	float w0, w1, u0_temp, u1_temp, u0, u1, delta_temp;
//	double delta_max = 0.0;
//	for (int i = 0; i < 256; i++)
//	{
//		//��ʼ����ز���
//		w0 = w1 = u0_temp = u1_temp = u0 = u1 = delta_temp = 0;
//		for (int j = 0; j < 256; j++)
//		{
//			//��������
//			if (j <= i)
//			{
//				//��ǰiΪ�ָ���ֵ����һ���ܵĸ���
//				w0 += nProDis[j];
//				u0_temp += j*nProDis[j];
//			}
//			//ǰ������
//			else
//			{
//				//��ǰiΪ�ָ���ֵ����һ���ܵĸ���
//				w1 += nProDis[j];
//				u1_temp += j*nProDis[j];
//			}
//		}
//		//�ֱ��������ƽ���Ҷ�
//		u0 = u0_temp / w0;
//		u1 = u1_temp / w1;
//		delta_temp = (float)(w0*w1*pow((u0 - u1), 2));
//		//�����ҵ������䷽���µ���ֵ
//		if (delta_temp > delta_max)
//		{
//			delta_max = delta_temp;
//			threshold = i;
//		}
//	}
//	return threshold;
//}


int main()
{
	//ͼ���ȡ���ж�
	Mat srcImage = imread("I.jpg");
	imshow("srcImage", srcImage);
	if (!srcImage.data)
		return 1;
	
	//GaussianBlur(srcImage, srcImage, Size(7, 7), 0, 0);



	////�Ҷ�ת��
	//Mat srcGray;
	//cvtColor(srcImage, srcGray, CV_RGB2GRAY);
	//imshow("srcGray", srcGray);
	//����OTSU��ֵ���㷨�õ���ֵ
	Mat ostuThreshold = OTSU(srcImage);
	cout << "ostu:" << ostuThreshold.channels() << endl;
	//cout << ostuThreshold << endl;

	////����������ͼ��
	//Mat otsuResultImage = Mat::zeros(srcGray.rows, srcGray.cols, CV_8UC1);
	////���õõ�����ֵʵ�ֶ�ֵ������
	//for (int i = 0; i < srcGray.rows; i++)
	//{
	//	for (int j = 0; j < srcGray.cols; j++)
	//	{
	//		if (srcGray.at<uchar>(i, j) > ostuThreshold)
	//		{
	//			otsuResultImage.at<uchar>(i, j) = 255;
	//		}
	//		else
	//		{
	//			otsuResultImage.at<uchar>(i, j) = 0;
	//		}
	//	}
	//}
	
	imshow("otsuResultImage", ostuThreshold);
	//imwrite("Hvalue.jpg", ostuThreshold);
	waitKey(0);

	return 0;

}