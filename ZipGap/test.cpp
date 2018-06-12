#include<iostream>
using namespace std;

class Parent {

};
class Child :public Parent {

};
int main() {
	Parent** arr = new Parent*[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = new Parent[10];
	}
}