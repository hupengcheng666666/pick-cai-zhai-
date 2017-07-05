#include <iostream>

// OpenCV Header
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

// Kinect for Windows SDK Header
#include <Kinect.h>

using namespace std;

int main(int argc, char** argv)
{
	// 1a. Get default Sensor
	cout << "Try to get default sensor" << endl;
	IKinectSensor* pSensor = nullptr;
	if (GetDefaultKinectSensor(&pSensor) != S_OK)
	{
		cerr << "Get Sensor failed" << endl;
	}
	
	
	// 1b. Open sensor
	cout << "Try to open sensor" << endl;
	if (pSensor->Open() != S_OK)
	{
		cerr << "Can't open sensor" << endl;
	}
		
	/*****************************************************************************/
	// 2a. Get frame source
	cout << "Try to get source" << endl;
	IDepthFrameSource* pDepthFrameSource = nullptr;
	if (pSensor->get_DepthFrameSource(&pDepthFrameSource) != S_OK)
	{
		cerr << "Can't get depth frame source" << endl;
	}
	IColorFrameSource* pColorFrameSource = nullptr;
	if (pSensor->get_ColorFrameSource(&pColorFrameSource) != S_OK)
	{
		cerr << "Can't get color frame source" << endl;
	}
			
/*******************************************************************************/
	// 2b. Get frame description
	int		iDepthWidth = 0;
	int		iDepthHeight = 0;
	IFrameDescription* pDepthDescription = nullptr;
	if (pDepthFrameSource->get_FrameDescription(&pDepthDescription) == S_OK)
	{
		pDepthDescription->get_Width(&iDepthWidth);
		pDepthDescription->get_Height(&iDepthHeight);
		pDepthDescription->Release();
		pDepthDescription = nullptr;
	}

	int     iColorWidth = 0;
	int     iColorHeight = 0;
	IFrameDescription* pColorDescription = nullptr;
	if (pColorFrameSource->get_FrameDescription(&pColorDescription) == S_OK)
	{
		pColorDescription->get_Width(&iColorWidth);
		pColorDescription->get_Height(&iColorHeight);
		pColorDescription->Release();
		pColorDescription = nullptr;
	}
/************************************************************************************/

	// 2c. get some dpeth only meta
	UINT16 uDepthMin = 0, uDepthMax = 0;
	pDepthFrameSource->get_DepthMinReliableDistance(&uDepthMin);
	pDepthFrameSource->get_DepthMaxReliableDistance(&uDepthMax);
	cout << "Reliable Distance: " << uDepthMin << " - " << uDepthMax << endl;

	// perpare OpenCV
	cv::Mat mDepthImg(iDepthHeight, iDepthWidth, CV_16UC1);
	cv::Mat mImg8bit(iDepthHeight, iDepthWidth, CV_8UC1);
	cv::namedWindow("Depth Map");

	cv::Mat mColorImg(iColorHeight, iColorWidth, CV_8UC4);
	UINT uBufferSize = iColorHeight*iColorWidth * 4 * sizeof(BYTE);
	cv::namedWindow("Color Map");
	/********************************************************************************/

	// 3a. get frame reader
	cout << "Try to get frame reader" << endl;
	IDepthFrameReader* pDepthFrameReader = nullptr;
	if (pDepthFrameSource->OpenReader(&pDepthFrameReader) != S_OK)
	{
		cerr << "Can't get depth frame reader" << endl;
	}

	IColorFrameReader* pColorFrameReader = nullptr;
	if (pColorFrameSource->OpenReader(&pColorFrameReader) != S_OK)
	{
		cerr << "Can't get color frame reader" << endl;
		return -1;
	}
	
	/********************************************************************************/
	// Enter main loop
	cout << "Enter main loop" << endl;
	while (true)
	{
		// 4a. Get last frame
		IDepthFrame* pDepthFrame = nullptr;
		if (pDepthFrameReader->AcquireLatestFrame(&pDepthFrame) == S_OK)
		{
			// 4c. copy the depth map to image
			if (pDepthFrame->CopyFrameDataToArray(iDepthWidth * iDepthHeight, reinterpret_cast<UINT16*>(mDepthImg.data)) == S_OK)
			{
				// 4d. convert from 16bit to 8bit
				mDepthImg.convertTo(mImg8bit, CV_8U, 255.0f / uDepthMax);
				cv::imshow("Depth Map", mImg8bit);
			}
			else
			{
				cerr << "Data copy error" << endl;
			}

			// 4e. release frame
			pDepthFrame->Release();
		}

		IColorFrame* pColorFrame = nullptr;
		if (pColorFrameReader->AcquireLatestFrame(&pColorFrame) == S_OK)
		{
			if (pColorFrame->CopyConvertedFrameDataToArray(uBufferSize, mColorImg.data, ColorImageFormat_Bgra) == S_OK)
			{
				cv::imshow("Color Map", mColorImg);
			}
			else
			{
				cerr << "Data copy error" << endl;
			}
			pColorFrame->Release();
		}

	/*******************************************************************************/
		// 4f. check keyboard input
		if (cv::waitKey(30) == VK_ESCAPE) {
			break;
		}
	}



/***********************************************************************************/





	// 3b. release frame reader
	cout << "Release frame reader" << endl;
	pDepthFrameReader->Release();
	pDepthFrameReader = nullptr;

	pColorFrameReader->Release();
	pColorFrameReader = nullptr;

	// 2d. release Frame source
	cout << "Release frame source" << endl;
	pDepthFrameSource->Release();
	pDepthFrameSource = nullptr;
		
	pColorFrameSource->Release();
	pColorFrameSource = nullptr;

	// 1c. Close Sensor
	cout << "close sensor" << endl;
	pSensor->Close();
		

	// 1d. Release Sensor
	cout << "Release sensor" << endl;
	pSensor->Release();
	pSensor = nullptr;
	
	return 0;
}