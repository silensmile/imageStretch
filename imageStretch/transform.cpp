#include"header.h"

Mat transform(Mat const src, vector<Point> Pointsrc) {
	int temp;
	std::sort(Pointsrc.begin(), Pointsrc.end(),
		[](Point point1, Point point2) {return point1.x < point2.x; }
	);
	if (Pointsrc[0].y > Pointsrc[1].y) {
		temp = Pointsrc[1].y;
		Pointsrc[1].y = Pointsrc[0].y;
		Pointsrc[0].y = temp;
	}
	if (Pointsrc[2].y > Pointsrc[3].y) {
		temp = Pointsrc[3].y;
		Pointsrc[3].y = Pointsrc[2].y;
		Pointsrc[2].y = temp;
	}
	Point2f srcPoint[4];
	srcPoint[0] = Pointsrc[0];
	srcPoint[1] = Pointsrc[1];
	srcPoint[2] = Pointsrc[2];
	srcPoint[3] = Pointsrc[3];
	Point2f dstPoint[4];
	dstPoint[0] = { 0,0 };
	dstPoint[1] = { 0,1500 };
	dstPoint[2] = { 2000,0 };
	dstPoint[3] = { 2000,1500 };
	Mat transformMatrix = getPerspectiveTransform(srcPoint, dstPoint);
	Mat dst(Size(2000,1500), src.type());
	warpPerspective(src,dst,transformMatrix,dst.size(), INTER_LINEAR, BORDER_CONSTANT);

	return dst;
}