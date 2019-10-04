#include "pch.h"
#include <iostream>
#include <set>
using namespace std;

int cyclelen(int d) {
	set<int> rems;
	int count = 1;
	int i = 1;
	while (rems.find(i * 10 % d) == rems.end()) {
		rems.insert(i * 10 % d);
		i = i * 10 % d;
		count++;
		if (i * 10 % d == 0) return 0;
	}
	return (count - 1);
}

int main() {
	int maximum = 0;
	int maxd = 0;
	for (int d = 2; d < 1000; d++) {
		if (cyclelen(d) > maximum) {
			maximum = cyclelen(d);
			maxd = d;
		}
	}
	cout << maxd << endl;
}