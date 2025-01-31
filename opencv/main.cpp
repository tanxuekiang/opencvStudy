#include <opencv2/opencv.hpp>
#include <iostream>
#include "quicopencv.h"
#include "quitest.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	// OpenCV版本号
	cout << "OpenCV_Version: " << CV_VERSION_MAJOR  << endl;

	// 读取图片
	Mat img = imread("C:/Users/f/Desktop/1.PNG");
	if (img.empty()) {
		std::cerr << "无法加载图像" << std::endl;
		return -1;
	}
	imshow("原图", img);
	//QuickDemo te;
	//te.colorspace_Demo(img);
	QuickDemo2 test;
	//test.Demo(img);
//test.trackbarllDemo();
	// 显示图片
//est.keyDemo(img);
	//test.colorstyleDemo(img);
	//test.btcountDemo(img);

	test.chanelDemo(img);
	waitKey(0); // 等待用户按键后退出
	return 0;
}
