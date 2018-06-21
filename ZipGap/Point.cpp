#include "Point.h"
Point::Point() {}
Point::Point(int _x, int _y) :x(_x), y(_y) {}
Point::Point(const Point& another) {
	x = another.x;
	y = another.y;
}

/*bool operator()(const Point& origin, const Point& another) const {
cout << "Ddwdqw";

if (x == another.x)
return y < another.y;
return x < another.x;
}*/

bool Point::operator<(const Point& another) const {
	if (x == another.x)
		return y < another.y;
	return x < another.x;
}
bool Point::operator<=(const Point& another) const {
	if (x == another.x)
		return y <= another.y;
	return x <= another.x;
}

bool Point::operator>(const Point& another) const {
	if (x == another.x)
		return y > another.y;
	return x > another.x;
}
bool Point::operator>=(const Point& another) const {
	if (x == another.x)
		return y >= another.y;
	return x >= another.x;
}

bool Point::operator == (const Point& another) const {
	return x == another.x && y == another.y;
}
int Point::GetX() const { return x; }
int Point::GetY() const { return y; }
ostream& operator<<(ostream& os, const Point& point)
{
	os << '(' << point.GetX() << ',' << point.GetY() << ')';
	return os;
}