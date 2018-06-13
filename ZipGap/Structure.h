#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

using namespace std;
class Structure {
protected:
	string name;
	Point point;
public:
	Structure() {
		name = "";
	}
	virtual void Print() {};
	Point GetPoint() const { return point; }
	string GetName() const { return name; }
	friend ostream& operator<<(ostream& os, const Structure& structure) {//지도에출력
		os << structure.name << structure.point;
		return os;
	}
	
};