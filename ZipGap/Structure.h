#pragma once
#include "Point.h"
#include "UnsortedType.h"
#include"TreeType.h"
#include <iostream>
#include <windows.h>
using namespace std;

using namespace std;
class Structure {
protected:
	string name;
	Point point;
	UnsortedType<Point> linkedStructure;
	
public:
	virtual void Print() const = 0 ;
	Point GetPoint() const { return point; }
	string GetName() const { return name; }
	void Link(Point item) {
		linkedStructure.InsertItem(item);
	}
	UnsortedType<Point> GetLinkList() const {
		return linkedStructure;
	}
	virtual void PrintMap() const = 0;
	//friend ostream& operator<<(ostream& os, const Structure& structure) {//지도에출력
	//	os << structure.name << structure.point;
	//	return os;
	//}
	
};