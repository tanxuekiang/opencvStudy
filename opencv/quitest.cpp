#include"quitest.h"
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
void onChangeTrackBarLights(int pos, void* userdata);
void onChangeTrackBarConstra(int pos, void* userdata);
void QuickDemo2::Demo(Mat& image)
{

	imshow("picture", image);
	int w = image.cols;
	int h = image.rows;
	int doms = image.channels();
	/*
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (doms=1) {//灰度图

				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;

			}
			if (doms == 3)
			{//彩色图
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col)[0]=255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}

	}*/


	for (int row = 0; row < h; row++)
	{
		uchar* cur_row = image.ptr<uchar>(row);

		for (int col = 0; col < w; col++)
		{
			if (doms == 1) {//灰度图




				int pv = *cur_row;
				*cur_row++ = 255 - pv;

			}
			if (doms == 3)
			{//彩色图
				*cur_row++ = 255 - *cur_row;
				*cur_row++ = 255 - *cur_row;
				*cur_row++ = 255 - *cur_row;
			}
		}

	}


	imshow("像素读写", image);

}
void QuickDemo2::opdationDemo(Mat &image) {

	imshow("picture", image);
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(8,8, 8);

	multiply(image,m,dst);
	
	//add(image, m, dst);
	//subtract(image, m, dst);
	//divide(image, m, dst);
	imshow("test", dst);
}
//TrackBar发生改变的回调函数
// 回调函数
void onChangeTrackBarLights(int pos, void* usrdata)
{
	// 强制类型转换
	Mat src = *(Mat*)(usrdata);
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat m = Mat::zeros(src.size(), src.type());
	m = Scalar(100,100,100);
	// 二值化
	addWeighted(src, 1.0,m,0, pos,dst);
	imshow("调整", dst);
}

void onChangeTrackBarConstra(int pos, void* usrdata)
{
	// 强制类型转换
	Mat src = *(Mat*)(usrdata);
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat m = Mat::zeros(src.size(), src.type());
	double con_val = pos / 100.0;
		// 二值化
	addWeighted(src, con_val, m, 0.0, pos, dst);
	imshow("调整", dst);
}
//主函数
void QuickDemo2::trackbarllDemo()
{
	//trackbar的值
	int posTrackBar = 0;
	//trackbar的最大值
	int maxValue = 100;

	//读入图像，以灰度图形式读入
	Mat img = imread("C:/Users/f/Desktop/1.PNG");

	//新建窗口
	namedWindow("调整");
	imshow("调整", img);
//rackbar，我们把img作为数据传进回调函数中
	createTrackbar("ps", "调整", &posTrackBar, maxValue, onChangeTrackBarLights,(void*)(&img));
	createTrackbar("pos", "调整", &posTrackBar, maxValue, onChangeTrackBarConstra, (void*)(&img));
	
	onChangeTrackBarLights(50, &img);
	onChangeTrackBarLights(50, &img);

	waitKey(0);
	return ;
}
void QuickDemo2::keyDemo(Mat& image) {

	
		Mat dst = Mat::zeros(image.size(), image.type());
		Mat m = Mat::zeros(image.size(), image.type());
	while (true)
	{
		int c = waitKey(100);
		if (c == 27)
		{
			cout << "you enter1" << endl;
			break;
		}
		if (c == 49)
		{
			cout << "you enter2" << endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == 50)
		{
			cout << "you enter3" << endl;
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		if (c == 51)
		{
			cout << "you enter4" << endl;
			m = Scalar(8, 8, 8);

			multiply(image, m, dst);
		}
		imshow("键盘响应", dst);
	}


}
void QuickDemo2::colorstyleDemo(Mat& image) {

	int colomap[] = {

		COLORMAP_AUTUMN,
COLORMAP_BONE,
COLORMAP_JET,
COLORMAP_WINTER,
COLORMAP_RAINBOW,
COLORMAP_OCEAN,
COLORMAP_SUMMER,
COLORMAP_SPRING,
COLORMAP_COOL,
COLORMAP_HSV,
COLORMAP_PINK,
COLORMAP_HOT,
COLORMAP_PARULA,
COLORMAP_MAGMA,
COLORMAP_INFERNO,
COLORMAP_PLASMA,
COLORMAP_VIRIDIS,
COLORMAP_CIVIDIS,
COLORMAP_TWILIGHT,
COLORMAP_TWILIGHT_SHIFTED,
COLORMAP_TURBO,
COLORMAP_DEEPGREEN,


	};
	Mat dst;
	int index = 0;
	while (true)
	{
		int c = waitKey(1000);
		if (c == 27)
		{
			break;
		}
		applyColorMap(image, dst, colomap[index % 21]);
		index++;
		imshow("颜色风格", dst);


	}

}
void QuickDemo2::btcountDemo(Mat& image)
{
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);

	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);

	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 0), -1, LINE_8, 0);
	
	imshow("图一",m1);
	imshow("图二",m2);
	Mat dst;
	//bitwise_or(m1, m2, dst);
	//bitwise_and(m1, m2, dst);
	//bitwise_not(m1,dst);
	bitwise_xor(m1,m2,dst);
	imshow("像素与操作", dst);

}
void QuickDemo2::chanelDemo(Mat& image)
{
	vector<Mat> mv;
	split(image, mv);
	imshow("蓝色", mv[0]);
	imshow("绿色", mv[1]);
	imshow("红色", mv[2]);

	/*Mat dst;
	mv[1] = 0;
	mv[2] = 0;
	merge(mv, dst);
	imshow("蓝色", dst);*/
/*
	Mat dst;
	mv[0] = 0;
	mv[2] = 0;
	merge(mv, dst);
	imshow("绿色", dst);
	*/
	Mat dst;
	mv[0] = 0;
	mv[1] = 0;
	merge(mv, dst);
	imshow("红色", dst);

}