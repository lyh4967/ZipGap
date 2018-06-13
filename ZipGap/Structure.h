#pragma once
#include "Point.h"
#include <iostream>
#include <windows.h>
using namespace std;

using namespace std;
class Structure {
protected:
	string name;
	Point point;
public:
	virtual void Print() {};
	Point GetPoint() const { return point; }
	string GetName() const { return name; }
	virtual void PrintMap() const = 0;
	//friend ostream& operator<<(ostream& os, const Structure& structure) {//지도에출력
	//	os << structure.name << structure.point;
	//	return os;
	//}
	
};