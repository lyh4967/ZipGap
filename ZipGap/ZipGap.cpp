// ZipGap.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "Simulator.h"
#include "House.h"
#include "stdafx.h"
using namespace std;

int main()
{
	cout << "Welcome to ZipGap simulator!" << endl;
	string command;
		Point p(5, 5);
		House h1(p, "이영훈",1500);
		h1.Print();
    return 0;
}

