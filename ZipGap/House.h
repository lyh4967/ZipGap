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
