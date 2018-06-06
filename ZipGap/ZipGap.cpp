// ZipGap.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "Simulator.h"
#include "House.h"
#include "Infra.h"
#include "stdafx.h"
#include "subFunc.h"
using namespace std;

Point make_point(int x, int y);
House make_house(Point point, string name, int price);
Infra make_Infra(Point point, string name, int weight);


int main()
{
	cout << "Welcome to ZipGap simulator!" << endl;
	ifstream commandInput("command.txt");
	string command;
	Simulator simulator;
	while (true) {
		simulator.Print();
		cout << "1. 집을 넣는다." << endl;
		cout << "2. 기반시설을 넣는다." << endl;
		cout << "3. 저장하기" << endl;
		cout << "q. 나가기" << endl;
		commandInput >> command;
		if (command == "1") {
			cout << "좌표를 입력해주세요.ex)1,1" << endl;
			commandInput >> command;
			string* tmpCommand=StringSplit(command, ",");
			int x = stoi(tmpCommand[0]);
			int y = stoi(tmpCommand[1]);

			cout << "이름과 초기가격을 입력해주세요.ex)마트1 1500" << endl;
			getline(commandInput, command);
			getline(commandInput, command);
			tmpCommand = StringSplit(command, " ");
			string name = tmpCommand[0];
			int price = stoi(tmpCommand[1]);
			House house(make_point(x, y), name, price);
			simulator.InsertHouse(house);
			cout << "입력이 완료되었습니다." << endl;
			house.Print();
		}
		else if (command == "3") {
			simulator.save();
		}
		else if (command == "q")
			break;
		else
			cout << "올바른 선택이 아닙니다. 다시 입력해주세요" << endl;
	}
	Point p(5, 5);
	House h1(p, "이영훈",1500);
	h1.Print();
    return 0;
}
Point make_point(int x, int y) {
	return Point(x, y);
}
House make_house(Point point, string name, int price) {
	return House(point, name, price);
}
Infra make_Infra(Point point, string name, int weight) {
	return Infra(point, name, weight);
}

