#include "Infra.h"
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << name << point;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}