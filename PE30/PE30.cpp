#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

bool writable(int n) {
	int mysum = 0;
	for (char c : to_string(n)) {
		mysum += pow(c - '0', 5);
	}
	return (n == mysum);
}

int main() {
	int mysum = 0;
	for (int i = 2; i < 1000000; i++) {
		if (writable(i)) mysum += i;
	}
	cout << mysum << endl;
}