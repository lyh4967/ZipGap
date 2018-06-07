#pragma once
#include "stdafx.h"
#include "House.h"
#include "Infra.h"
using namespace std;

class Simulator {
private:
	string** realtyMap;
	map<Point, House> houseList;
	map<Point, Infra> infraList;//포인트로하자
	int maxSize;
	ofstream output;
	ifstream input;
	
	void checkPrice_house();
	void checkPrice_target(Point p);
public:
	Simulator();
	~Simulator();
	void Print() const;
	void InsertHouse(House& house);
	void InsertInfra(Infra& infra);
	void Save(string outputPath_);
	void Load(string inputPath_);
	bool checkPromising(Point p);

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
	cout << "=========================================" << endl;
	cout << "================House LIst===============" << endl;
	for (auto item : houseList)
		item.second.Print();
	cout << "=========================================" << endl;
	cout << "================Infra LIst===============" << endl;
	for (auto item : infraList)
		item.second.Print();
	cout << "=========================================" << endl;
}

void Simulator::InsertHouse(House& house) {
	Point point = house.GetPoint();
	houseList.insert(make_pair(point, house));
	int x = point.GetX();
	int y = point.GetY();
	realtyMap[y][x] = house.GetName()+"("+to_string(x)+","+to_string(y)+")";
	checkPrice_target(point);
}

void Simulator::InsertInfra(Infra& infra) {
	Point point = infra.GetPoint();
	infraList.insert(make_pair(point, infra));
	int x = point.GetX();
	int y = point.GetY();

	realtyMap[y][x] = infra.GetName() + "(" + to_string(x) + "," + to_string(y) + ")";
	checkPrice_house();
}

void Simulator::Save(string outputPath_) {//1. houseList 저장, 2. InfraList 저장
	string outputPath = outputPath_+"_house.dat";
	output.open(outputPath, ios::out | ios::binary);
	for (auto item : houseList) {//집 리스트저장
		output.write((char*)&item, sizeof(item));
	}
	output.close();

	outputPath = outputPath_+"_infra.dat";
	output.open(outputPath, ios::out | ios::binary);
	for (auto item : infraList) {//인프라 리스트 저장
		output.write((char*)&item, sizeof(item));
	}
	output.close();
}

void Simulator::Load(string inputPath_) {
	string inputPath = inputPath_ + "_house.dat";
	input.open(inputPath, ios::in | ios::binary);
	pair<Point, House> item_h;

	while (input.read((char*)& item_h, sizeof(item_h))) {
		houseList.insert(item_h);
	}
	input.close();

	inputPath = inputPath_ + "_infra.dat";
	input.open(inputPath, ios::in | ios::binary);

	pair<Point, Infra> item_i;

	while (input.read((char*)& item_i, sizeof(item_i))) {
		infraList.insert(item_i);
	}

	input.close();
}

void Simulator::checkPrice_house() {
	for (auto& item_h : houseList) {
		House house = item_h.second;
		int price = house.GetPrice();
		for (auto item_i : infraList) {
			Infra infra = item_i.second;
			int distX = pow(house.GetPoint().GetX() - infra.GetPoint().GetX(),2);
			int distY = pow(house.GetPoint().GetY() - infra.GetPoint().GetY(),2);
			int dist = (int)sqrt(distX + distY);//건물사이의 거리
			price += infra.GetWeighted()/dist*10;//10의 가중을 더준다.
			
		}
		item_h.second.SetPrice(price);
	}
	//for (map<string, House>::iterator item_h = houseList.begin(); item_h != houseList.end(); item_h++) {
	//	House house = (*item_h).second;
	//	int price = house.GetPrice();
	//	for (map<string, Infra>::iterator item_i = infraList.begin(); item_i != infraList.end(); item_i++) {
	//		Infra infra = (*item_i).second;
	//		int distX = pow(house.GetPoint().GetX() - infra.GetPoint().GetX(), 2);
	//		int distY = pow(house.GetPoint().GetY() - infra.GetPoint().GetY(), 2);
	//		int dist = (int)sqrt(distX + distY);//건물사이의 거리
	//		price += dist * infra.GetWeighted();

	//	}
	//	(*item_h).second.SetPrice(price);
	//}
}

void Simulator::checkPrice_target(Point p) {
	map<Point, House>::iterator iter = houseList.find(p);
	House house = (*iter).second;
	int price = house.GetPrice();
	for (auto item_i : infraList) {
		Infra infra = item_i.second;
		int distX = pow(house.GetPoint().GetX() - infra.GetPoint().GetX(), 2);
		int distY = pow(house.GetPoint().GetY() - infra.GetPoint().GetY(), 2);
		int dist = (int)sqrt(distX + distY);//건물사이의 거리
		price += infra.GetWeighted() / dist * 10;//10의 가중을 더준다.
	}
	(*iter).second.SetPrice(price);
}

bool Simulator::checkPromising(Point p) {
	bool promising = true;
	if (houseList.find(p) != houseList.end())
		promising = false;
	if (infraList.find(p) != infraList.end())
		promising = false;
	return promising;
}