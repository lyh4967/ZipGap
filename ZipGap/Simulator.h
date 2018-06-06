#pragma once
#include "stdafx.h"
#include "House.h"
#include "Infra.h"
using namespace std;

class Simulator {
private:
	string** realtyMap;
	map<string, House> houseList;
	map<string, Infra> infraList;
	int maxSize;
	ofstream output;
	ifstream input;
public:
	Simulator();
	~Simulator();
	void Print() const;
	void InsertHouse(House& house);
	void save();

};

Simulator::Simulator()
//차후 사용자입력 동적할당예정 
{
	int _maxSize = 16;
	maxSize = _maxSize;
	realtyMap = new string*[maxSize];
	for (int i = 0; i < maxSize; i++) {
		realtyMap[i] = new string[maxSize];
		fill(realtyMap[i], realtyMap[i] + maxSize, "");
	}
}
Simulator::~Simulator() {
	for(int i=0;i<maxSize;i++)
		delete [] realtyMap[i];
}

void Simulator::Print() const
//지도의 모든 요소를 출력한다.
{
	cout << "========================================" << endl;
	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < maxSize; j++) {
			cout << realtyMap[i][j] << setw(4);
		}
		cout << endl;
	}
	cout << "========================================" << endl;
}

void Simulator::InsertHouse(House& house) {
	houseList.insert(make_pair(house.GetName(), house));
	int x = house.GetPoint().GetX();
	int y = house.GetPoint().GetY();

	realtyMap[y][x] = house.GetName()+"("+to_string(x)+","+to_string(y)+")";
}

void Simulator::save() {
	string outputPath = "saveData.dat";
	output.open(outputPath, ios::out | ios::binary);
	for (int i = 0; i < houseList.size(); i++) {//저장 기능 구현중
	}

}