#pragma once
#include "Structure.h"
class Infra:public Structure {
private:
	int weight;
public:
	Infra();
	Infra(Point _point, string _name, int _weight);
	~Infra();
	void Print() const;
};
Infra::Infra() {}

Infra::Infra(Point _point, string _name, int _weight) {
	point = _point;
	name = _name;
	weight = _weight;
}
Infra::~Infra() {}

void Infra::Print() const {
	cout << name << point << ":" << weight << endl;
}