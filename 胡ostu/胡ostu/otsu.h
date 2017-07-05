#pragma once
#include <stdio.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat OTSU(cv::Mat srcImage);
