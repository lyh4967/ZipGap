#include<iostream>
#include <string>
#include "TreeType.h"
#include "Point.h"
using namespace std;

int main() {

	Point p(2, 3);
	TreeType<Point> tree;
	tree.InsertItem(p);
	bool found = false;
	tree.ResetTree(PRE_ORDER);
	bool finished = false;
	while (!finished) {
		Point tmp;
		tree.GetNextItem(tmp,PRE_ORDER, finished);
		cout << tmp;
	}

	return 0;
}
