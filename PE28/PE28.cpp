#include "pch.h"
#include <iostream>
using namespace std;

int mysum = 0;

void add(int addend, int delta) {
	while (addend <= 1001 * 1001) {
		mysum += addend;
		addend += delta;
		delta += 8;
	}
}

int main() {
	add(1, 8); // up right
	add(1, 2); // down right
	add(1, 4); // down left
	add(1, 6); // up left

	mysum -= 3;

	cout << mysum << endl;
}