#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main() {
	Mat srcMat = imread("D:\\etest.jpg", 0);
	Mat dstMat;
	if (srcMat.type() == CV_8UC1) {
		equalizeHist(srcMat, dstMat);
	}
	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
		Mat out[3];
		split(srcMat, channel);

		for (int i = 0; i < 3; i++) {
			equalizeHist(channel[i], out[i]);
		}

		merge(out, 3, dstMat);
	}
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);
}

