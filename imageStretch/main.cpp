#include"header.h"

void main() {
	const Mat src = imread("./img/src2.jpg");
	namedWindow("src", 2);
	imshow("src", src);

	vector<Point> srcPoint = preProcess(src);
	Mat dst = transform(src, srcPoint);

	namedWindow("dst", 2);
	imshow("dst", dst);

	waitKey(0);
}