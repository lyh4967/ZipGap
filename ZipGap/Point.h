#pragma once
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point() {}
	Point(int _x, int _y) :x(_x), y(_y) {}
	
	/*bool operator()(const Point& origin, const Point& another) const {
		cout << "Ddwdqw";

		if (x == another.x)
			return y < another.y;
		return x < another.x;
	}*/

	bool operator<(const Point& another) const {
		if (x == another.x)
			return y < another.y;
		return x < another.x;
	}
/*
	bool operator == (const Point& another) const {
		return x == another.x && y == another.y;
	}*/

	friend ostream& operator<<(ostream& os, const Point& point);
	
	int GetX() const { return x; }
	int GetY() const { return y; }
};
ostream& operator<<(ostream& os, const Point& point)
{
	os << '('<<point.GetX() << ',' << point.GetY() << ')';
	return os;
}