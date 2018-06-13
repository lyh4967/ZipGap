#pragma once
#include "Structure.h"
#include "stdafx.h"
class House :public Structure {
private:
	int price;
public:
	House();
	House(Point _point, string _name, int _price);
	~House();
	void Print() const;
	virtual void PrintMap() const;
	int GetPrice() const;
	void SetPrice(int price_);
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

int House::GetPrice() const {
	return price;
}

void House::SetPrice(int price_) {
	price = price_;
}

void House::PrintMap() const {
	cout<< name << point;
}