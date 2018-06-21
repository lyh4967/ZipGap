#pragma once
#include "stdafx.h"
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point();
	Point(int _x, int _y);
	Point(const Point& another);
	
	//bool operator()(const Point& origin, const Point& another) const;

	bool operator<(const Point& another) const;
	bool operator<=(const Point& another) const;

	bool operator>(const Point& another) const;
	bool operator>=(const Point& another) const;

	bool operator == (const Point& another) const;
	friend ostream& operator<<(ostream& os, const Point& point);
	
	int GetX() const;
	int GetY() const;
};
