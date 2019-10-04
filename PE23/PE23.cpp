// PE23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int sum(set<int> s) {
	int mysum = 0;
	for (int i : s) {
		mysum += i;
	}
	return mysum;
}
int sumdiv(int n) {
	int num = 0;
	// square number case
	if (sqrt(n) == (int)sqrt(n)) {
		for (int f = 1; f <= sqrt(n); f++) {
			if (n % f == 0) {
				num += f + n / f;
			}
		}
		num -= (int)sqrt(n);
		return num - n;
	}
	else {
		for (int f = 1; f <= sqrt(n); f++) {
			if (n % f == 0) {
				num += f + n / f;
			}
		}
		return num - n;
	}
}
int main() {
	// first find all the abundant numbers
	// then find all the sums that can be found using them

	vector<int> abundants;
	// find all the abundant numbers
	for (int i = 1; i <= 28123; i++) {
		if (sumdiv(i) > i) {
			abundants.push_back(i);
		}
	}
	// find all the sums that can be found using them
	set<int> sums;

	for (int i = 0; i < abundants.size(); i++) {
		for (int j = i; j < abundants.size(); j++) {
			if (abundants[i] + abundants[j] <= 28123) {
				sums.insert(abundants[i] + abundants[j]);
			}
		}
	}
	// subtract out all the abundants
	cout << 28123 * (28123 + 1) / 2 - sum(sums) << endl;
}