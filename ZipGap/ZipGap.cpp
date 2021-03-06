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
	string* splitCommand;
	Simulator simulator;
	//simulator.Load("saveData");
	//키 값을 무엇으로 정해야하나.
	while (true) {
		cout << "1. 현황보기." << endl;
		cout << "2. 집을 넣는다." << endl;
		cout << "3. 기반시설을 넣는다." << endl;
		cout << "4. 건물을 지운다." << endl;
		cout << "5. 연결하기." << endl;
		cout << "q. 나가기" << endl;
		cin >> command;
		if (command == "1") {//현황출력
			simulator.Print();
		}
		else if (command == "2") {//House 입력
			cout << "좌표를 입력해주세요.ex)1,1" << endl;
			cin >> command;
			splitCommand =StringSplit(command, ",");
			int x = stoi(splitCommand[0]);
			int y = stoi(splitCommand[1]);
			Point newPoint(x, y);
			if (simulator.checkEmpty(newPoint)) {

				cout << "이름과 초기가격을 입력해주세요.ex)집1 1500" << endl;
				getline(cin, command);
				getline(cin, command);
				splitCommand = StringSplit(command, " ");
				string name = splitCommand[0];
				int price = stoi(splitCommand[1]);

				House* house=new House(newPoint, name, price);
				simulator.InsertHouse(house);

				cout << "입력이 완료되었습니다." << endl;
				house->Print();
			}
			else {
				cout << "해당좌표에 Structure가 존재합니다." << endl;
			}
		}
		else if (command == "3") {//Infra입력
			cout << "좌표를 입력해주세요.ex)1,1" << endl;

			cin >> command;

			splitCommand = StringSplit(command, ",");

			int x = stoi(splitCommand[0]);

			int y = stoi(splitCommand[1]);


			Point newPoint(x, y);
			if (simulator.checkEmpty(newPoint)) {
				cout << "이름과 가중치(-50 ~ 50)를 입력해주세요.ex)마트1 30" << endl;
				getline(cin, command);
				getline(cin, command);
				splitCommand = StringSplit(command, " ");
				string name = splitCommand[0];
				int weighted = stoi(splitCommand[1]);

				Infra* infra=new Infra(newPoint, name, weighted);
				simulator.InsertInfra(infra);
				cout << "입력이 완료되었습니다." << endl;
				infra->Print();
			}
			else {
				cout << "해당좌표에 Structure가 존재합니다." << endl;
			}
		}
		else if (command == "4") {//Structure 삭제
			cout << "좌표를 입력해주세요.ex)1,1" << endl;
			cin >> command;
			splitCommand = StringSplit(command, ",");
			int x = stoi(splitCommand[0]);
			int y = stoi(splitCommand[1]);
			Point targetPoint(x, y);
			if (!simulator.checkEmpty(targetPoint)) {//좌표에 건물이 존재
				simulator.DeleteStructure(targetPoint);
				cout << "건물이 삭제되었습니다." << endl;
			}
			else
				cout << "해당 좌표에 건물이 존재하지 않습니다." << endl;
		}
		else if (command == "5") {//건물 연결하기
			cout << "연결할 건물의 좌표를 입력해주세요. ex)1,1 2,2" << endl;
			cin >> command;
			splitCommand = StringSplit(command, ",");
			int x = stoi(splitCommand[0]);
			int y = stoi(splitCommand[1]);
			Point firstPoint(x, y);//첫번째 좌표

			cin >> command;
			splitCommand = StringSplit(command, ",");
			x = stoi(splitCommand[0]);
			y = stoi(splitCommand[1]);
			Point secondPoint(x, y);//두번째 좌표
			cout << firstPoint << secondPoint << endl;
			if (!simulator.checkEmpty(firstPoint) && !simulator.checkEmpty(secondPoint)) {
				simulator.LinkStructure(firstPoint, secondPoint);
				cout << "연결되었습니다." << endl;
			}
			else
				cout << "건물이 존재하지 않는 좌표가 입력되었습니다.";
		}
		else if (command == "-1") {//저장
			simulator.Save("saveData");
			cout << "저장완료!!" << endl;
		}
		else if (command == "q")//나가기
			break;
		else
			cout << "올바른 선택이 아닙니다. 다시 입력해주세요" << endl;
		cout << endl;
		cout << endl;
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

