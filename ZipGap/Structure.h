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
	Point GetPoint() const;
	string GetName() const;
	void Link(Point item);
	UnsortedType<Point> GetLinkList() const;
	virtual void PrintMap() const = 0;
	//friend ostream& operator<<(ostream& os, const Structure& structure);//지도에출력

};