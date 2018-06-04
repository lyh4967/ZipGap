#pragma once
#include "stdafx.h"
class Point {
private:
	int x;
	int y;
public:
	Point() {}
	Point(int _x, int _y) :x(_x), y(_y) {}
	friend ostream& operator<<(ostream& os, const Point& point);
	int GetX() const { return x; }
	int GetY() const { return y; }
};
ostream& operator<<(ostream& os, const Point& point)
{
	os << '('<<point.GetX() << ',' << point.GetY() << ')';
	return os;
}