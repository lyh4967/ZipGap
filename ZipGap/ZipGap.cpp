// ZipGap.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include "Simulator.h"
#include "House.h"
#include "Infra.h"
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
	//simulator.Load("saveData");
	//키 값을 무엇으로 정해야하나.
	while (true) {
		cout << "1. 현황보기." << endl;
		cout << "2. 집을 넣는다." << endl;
		cout << "3. 기반시설을 넣는다." << endl;
		cout << "4. 저장하기" << endl;
		cout << "q. 나가기" << endl;
		commandInput >> command;
		if (command == "1") {
			simulator.Print();
		}
		else if (command == "2") {
			cout << "좌표를 입력해주세요.ex)1,1" << endl;
			commandInput >> command;
			string* tmpCommand=StringSplit(command, ",");
			int x = stoi(tmpCommand[0]);
			int y = stoi(tmpCommand[1]);
			Point newPoint(x, y);
			if (simulator.checkPromising(newPoint)) {

				cout << "이름과 초기가격을 입력해주세요.ex)집1 1500" << endl;
				getline(commandInput, command);
				getline(commandInput, command);
				tmpCommand = StringSplit(command, " ");
				string name = tmpCommand[0];
				int price = stoi(tmpCommand[1]);

				House house(newPoint, name, price);
				simulator.InsertHouse(house);

				cout << "입력이 완료되었습니다." << endl;
				house.Print();
			}
			else {
				cout << "해당좌표에 Structure가 존재합니다." << endl;
			}
		}
		else if (command == "3") {
			cout << "좌표를 입력해주세요.ex)1,1" << endl;
			commandInput >> command;
			string* tmpCommand = StringSplit(command, ",");
			int x = stoi(tmpCommand[0]);
			int y = stoi(tmpCommand[1]);

			Point newPoint(x, y);
			if (simulator.checkPromising(newPoint)) {
				cout << "이름과 가중치(-50 ~ 50)를 입력해주세요.ex)마트1 30" << endl;
				getline(commandInput, command);
				getline(commandInput, command);
				tmpCommand = StringSplit(command, " ");
				string name = tmpCommand[0];
				int weighted = stoi(tmpCommand[1]);
				Infra infra(newPoint, name, weighted);
				simulator.InsertInfra(infra);
				cout << "입력이 완료되었습니다." << endl;
				infra.Print();
			}
			else {
				cout << "해당좌표에 Structure가 존재합니다." << endl;
			}
		}
		else if (command == "4") {
			simulator.Save("saveData");
			cout << "저장완료!!" << endl;
		}
		else if (command == "q")
			break;
		else
			cout << "올바른 선택이 아닙니다. 다시 입력해주세요" << endl;
	}
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

