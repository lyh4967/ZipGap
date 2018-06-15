#pragma once
#include "Point.h"
#include "UnsortedType.h"
#include <iostream>
#include <windows.h>
using namespace std;

using namespace std;
class Structure {
protected:
	string name;
	Point point;
	UnsortedType<Structure*> linkedStructure;
	
public:
	virtual void Print() const = 0 ;
	Point GetPoint() const { return point; }
	string GetName() const { return name; }
	void Link(Structure* item) {
		linkedStructure.InsertItem(item);
	}
	virtual void PrintMap() const = 0;
	//friend ostream& operator<<(ostream& os, const Structure& structure) {//지도에출력
	//	os << structure.name << structure.point;
	//	return os;
	//}
	
};