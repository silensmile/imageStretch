#include"header.h"

vector<Point> preProcess(const Mat src) {
	Mat srcChangeable;
	cvtColor(src, srcChangeable, CV_RGB2GRAY, 0);

	adaptiveThreshold(srcChangeable, srcChangeable, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, src.rows / 2 + 1, -10);
	erode(srcChangeable, srcChangeable, getStructuringElement(MORPH_RECT, Size(40, 40), Point(-1, -1)), Point(-1, -1), 1, 0);	//MORPH_ELLIPSE | MORPH_RECT
	dilate(srcChangeable, srcChangeable, getStructuringElement(MORPH_RECT, Size(40, 40), Point(-1, -1)), Point(-1, -1), 1, 0);
	vector<vector<Point>>contours;
	vector<Vec4i> hierarchy;
	findContours(srcChangeable, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<vector<Point>> contours_poly(contours.size());
	std::sort(contours.begin(), contours.end(),
		[](vector<Point> contours1, vector<Point> contours2) {return contours1.size() > contours2.size(); }
	);
	approxPolyDP(contours[0], contours[0], src.rows / 25.0, true);

	return contours[0];
}