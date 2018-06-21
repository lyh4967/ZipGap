#pragma once
#include "stdafx.h"
#include "House.h"
#include "Infra.h"
#include "QueType.h"
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
	TreeType<Point> checkLink_BFS(Structure* structure);
public:
	Simulator();//create map
	~Simulator();
	void Print();//print Structure list
	void InsertHouse(House* house);//inset house
	void InsertInfra(Infra* infra);//insert infra
	void DeleteStructure(Point point);//deletee structure(house or infra)
	void Save(string outputPath_);//save current data
	void Load(string inputPath_);//load previous data
	bool checkEmpty(Point p);//check whether insert possible
	void LinkStructure(Point p1, Point p2);//link structure between structure

};
bool checkVisited(TreeType<Point>& list, Point& p);
