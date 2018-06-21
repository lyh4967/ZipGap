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
