#include "pch.h"
#include <iostream>
using namespace std;

bool checksol(int n) {
	for (int i = 1; i <= 20; i++) {
		if (n % i != 0) return false;
	}
	return true;
}

int main() {
	int p = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
	int i = 0;
	while (true) {
		i += p;
		if (checksol(i)) {
			cout << i << endl;
			return 0;
		}
	}
}