#include<iostream>
#include <string>
using namespace std;
string s = "DDWDWWW";
class Parent {
public:
	virtual void print() { cout << s; }
};
class Child :public Parent {
public:
	virtual void print() { cout << s; }
};
int main() {
	Parent** arr = new Parent*[10];
	for (int i = 0; i < 10; i++) {
		arr[i]=new Parent[10];
	}
	Child ch;
	arr[0][0] = ch;
	arr[0][0].print();
}