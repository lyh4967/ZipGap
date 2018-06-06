#pragma once
#include "stdafx.h"
#include "Point.h"
using namespace std;
class Structure {
protected:
	string name;
	Point point;
public:
	Structure() {}
	virtual void Print() const = 0;
	Point GetPoint() { return point; }
	
};