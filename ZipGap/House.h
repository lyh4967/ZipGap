#pragma once
#include "Structure.h"
#include "stdafx.h"
class House :public Structure {
private:
	int price;
	int priceOrigin;
	int priceChange;
public:
	House();
	House(Point _point, string _name, int _price);
	~House();
	void Print() const;
	virtual void PrintMap() const;
	int GetPriceOrigin() const;
	void SetPriceOrigin(int priceOrigin_);
	int GetPrice() const;
	int GetPriceChange() const;
	void SetPrice(int price_);
	void SetPriceChange(int priceChange_);
};

House::House() {}

House::House(Point _point, string _name, int _price) {
	point = _point;
	name = _name;
	priceOrigin = _price;
	price = _price;
	priceChange=0;
}
House::~House() {}

void House::Print() const {
	cout << name << point << ":" << price;
}

int House::GetPrice() const {
	return price;
}

void House::SetPrice(int price_) {
	price = price_;
}

int House::GetPriceOrigin() const {
	return priceOrigin;
}

void House::SetPriceOrigin(int _priceOrigin) {
	priceOrigin = _priceOrigin;
}
int House::GetPriceChange() const {
	return priceChange;
}

void House::SetPriceChange(int _priceChange) {
	priceChange = _priceChange;
}

void House::PrintMap() const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout<< name << point;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}