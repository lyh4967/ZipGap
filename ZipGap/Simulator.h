#pragma once
#include "stdafx.h"
#include "House.h"
#include "Infra.h"
using namespace std;

class Simulator {
private:
	Structure*** realtyMap;
	map<Point, House*> houseList;
	map<Point, Infra*> infraList;//포인트로하자
	int maxSize;
	ofstream output;
	ifstream input;
	
	void checkPrice_house();//전체 집값을 체크한다.
	void checkPrice_target(Point p);//하나의 집값을 체크한다.
public:
	Simulator();//create map
	~Simulator();
	void Print() const;//print Structure list
	void InsertHouse(House* house);//inset house
	void InsertInfra(Infra* infra);//insert infra
	void DeleteStructure(Point point);//deletee structure(house or infra)
	void Save(string outputPath_);//save current data
	void Load(string inputPath_);//load previous data
	bool checkEmpty(Point p);//check whether insert possible
	void LinkStructure(Point p1, Point p2);//link structure between structure

};


Simulator::Simulator()
//차후 사용자입력 동적할당예정 
{
	int _maxSize = 16;
	maxSize = _maxSize;
	realtyMap = new Structure**[maxSize];
	for (int i = 0; i < maxSize; i++) {
		realtyMap[i] = new Structure*[maxSize];
	}
	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < maxSize; j++) {
			realtyMap[i][j] = NULL;
		}
	}
}
Simulator::~Simulator() {
	for(int i=0;i<maxSize;i++)
		delete [] realtyMap[i];
}

void Simulator::Print() const
//지도의 모든 요소를 출력한다.
{
	for (int i = 0; i < maxSize * 4; i++)
		cout << "=";
	cout << maxSize << endl;
	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < maxSize; j++) {
			if (realtyMap[i][j]==NULL)//객체가 있다면
				cout << "";
			else
				realtyMap[i][j]->PrintMap();
			cout << setw(4);
		}
		cout << endl;
	}
	for (int i = 0; i < maxSize * 4; i++)
		cout << "=";
	cout << endl;
	cout << "================House LIst===============" << endl;
	for (auto item : houseList)
		item.second->Print();
	cout << "=========================================" << endl;
	cout << "================Infra LIst===============" << endl;
	for (auto item : infraList)
		item.second->Print();
	cout << "=========================================" << endl;
}

void Simulator::InsertHouse(House* house) {//집 추가
	Point point = house->GetPoint();
	houseList.insert(make_pair(point, house));
	int x = point.GetX();
	int y = point.GetY();
	realtyMap[x][y] = house;
	checkPrice_target(point);
}

void Simulator::InsertInfra(Infra* infra) {//기반시설 추가
	Point point = infra->GetPoint();
	infraList.insert(make_pair(point, infra));
	int x = point.GetX();
	int y = point.GetY();

	realtyMap[x][y] = infra;
	checkPrice_house();
}
void Simulator::DeleteStructure(Point point) {//건물 삭제
	map<Point, Infra*>::iterator iter1;
	map<Point, House*>::iterator iter2;
	
	int x = point.GetX();
	int y = point.GetY();
	
	realtyMap[x][y] = NULL;
	iter1=infraList.find(point);
	if (iter1 != infraList.end()) {
		infraList.erase(point);
		checkPrice_house();
		return;
	}
	iter2 = houseList.find(point);
	if (iter2 != houseList.end()) {
		houseList.erase(point);
	}

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
	pair<Point, House*> item_h;

	while (input.read((char*)& item_h, sizeof(item_h))) {
		houseList.insert(item_h);
	}
	input.close();

	inputPath = inputPath_ + "_infra.dat";
	input.open(inputPath, ios::in | ios::binary);

	pair<Point, Infra*> item_i;

	while (input.read((char*)& item_i, sizeof(item_i))) {
		infraList.insert(item_i);
	}

	input.close();
}

void Simulator::checkPrice_house() {
	for (auto& item_h : houseList) {//건물 하나씩 반복
		House* house = item_h.second;
		int priceOrigin = house->GetPriceOrigin();
		int priceChange = 0;
		for (auto item_i : infraList) {//건물 하나당 모든 기반시설 반복
			Infra* infra = item_i.second;
			int distX = (int)pow(house->GetPoint().GetX() - infra->GetPoint().GetX(),2);
			int distY = (int)pow(house->GetPoint().GetY() - infra->GetPoint().GetY(),2);
			int dist = (int)sqrt(distX + distY);//건물사이의 거리
			priceChange += infra->GetWeighted()/dist*100;//10의 가중을 더준다.
		}
		item_h.second->SetPrice(priceOrigin+priceChange);
		item_h.second->SetPriceChange(priceChange);
	}
}

void Simulator::checkPrice_target(Point p) {
	map<Point, House*>::iterator iter = houseList.find(p);
	House* house = (*iter).second;
	int price = house->GetPrice();
	for (auto item_i : infraList) {
		Infra* infra = item_i.second;
		int distX = (int)pow(house->GetPoint().GetX() - infra->GetPoint().GetX(), 2);
		int distY = (int)pow(house->GetPoint().GetY() - infra->GetPoint().GetY(), 2);
		int dist = (int)sqrt(distX + distY);//건물사이의 거리
		price += infra->GetWeighted() / dist * 10;//10의 가중을 더준다.
	}
	(*iter).second->SetPrice(price);
}

bool Simulator::checkEmpty(Point p) {
	bool promising = true;
	/*if (houseList.find(p) != houseList.end())
		promising = false;
	if (infraList.find(p) != infraList.end())
		promising = false;*/
	if (realtyMap[p.GetX()][p.GetY()] != NULL)
		promising = false;
	return promising;
}

void Simulator::LinkStructure(Point p1, Point p2) {
	realtyMap[p1.GetX()][p1.GetY()]->Link(realtyMap[p2.GetX()][p2.GetY()]);
	realtyMap[p2.GetX()][p2.GetY()]->Link(realtyMap[p1.GetX()][p1.GetY()]);

}