#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcMat = imread("D:\\gtest.jpg", 0);
	Mat dstMat1;
	srcMat.copyTo(dstMat1);
	int k;
	float LUT1[256];
	float gamma1 = 0.33;
	for (int i = 0; i < 256; i++) {
		LUT1[i] = (float)i / 255;
		LUT1[i] = pow(LUT1[i], gamma1);
		LUT1[i] = (int)(LUT1[i] * 255);
	}
	for (int i = 0; i < srcMat.rows; i++) {
		for (int j = 0; j < srcMat.cols; j++) {
			k = srcMat.at<uchar>(i, j);
			dstMat1.at<uchar>(i, j) = LUT1[k];

		}
	}

	imshow("1", srcMat);
	imshow("2", dstMat1);
	waitKey(0);
}