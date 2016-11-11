#ifndef HEADER
#define HEADER

#include"iostream"
#include"opencv2/opencv.hpp"

using namespace std;
using namespace cv;

vector<Point> preProcess(const Mat src);
Mat transform(Mat const src, vector<Point> srcPoint);

#endif // !HEADER
