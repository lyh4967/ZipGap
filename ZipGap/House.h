#pragma once
#include "Structure.h"
class House :public Structure {
private:
	int price;
public:
	House();
	House(Point _point, string _name, int _price);
	~House();
	void Print() const;
};

House::House() {}

House::House(Point _point, string _name, int _price) {
	point = _point;
	name = _name;
	price = _price;
}
House::~House() {}

void House::Print() const {
	cout << name << point << ":" << price << endl;
}