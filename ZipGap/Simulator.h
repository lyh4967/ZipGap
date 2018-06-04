#pragma once
#include "stdafx.h"
using namespace std;

class Simulator {
private:
	string** realtyMap;
	int maxSize;
public:
	Simulator();
	~Simulator();
	void Print() const;
};

Simulator::Simulator()
//차후 사용자입력 동적할당예정 
{
	int _maxSize = 51;
	realtyMap = new string*[_maxSize];
	for (int i = 0; i < _maxSize; i++) {
		realtyMap[i] = new string[_maxSize];
		fill(realtyMap[i], realtyMap[i] + _maxSize, "");
	}
}
Simulator::~Simulator() {
	for(int i=0;i<maxSize;i++)
		delete [] realtyMap[i];
}

void Simulator::Print() const
//지도의 모든 요소를 출력한다.
{
	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < maxSize; j++) {
			cout << realtyMap[i][j] << " ";
		}
		cout << endl;
	}
}