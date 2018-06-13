#pragma once
#include "Structure.h"
class Infra:public Structure {
private:
	int weighted;
public:
	Infra();
	Infra(Point _point, string _name, int _weight);
	~Infra();
	void Print() const;
	virtual void PrintMap() const;
	int GetWeighted() const;
	void SetWeighted(int weighted_);
};
Infra::Infra() {}

Infra::Infra(Point _point, string _name, int _weighted) {
	point = _point;
	name = _name;
	weighted = _weighted;
}
Infra::~Infra() {}

void Infra::Print() const {
	cout << name << point << ":" << weighted << endl;
}

int Infra::GetWeighted() const {
	return weighted;
}
void Infra::SetWeighted(int weighted_) {
	weighted = weighted_;
}

void Infra::PrintMap() const {
	cout << name << point;
}