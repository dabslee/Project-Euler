
#include "pch.h"
#include <iostream>
using namespace std;

const int M = 1000000;
int chainlengths[M];

int findlength(unsigned long long n) {
	if (n >= M) {
		if (n % 2 == 0) return findlength(n / 2) + 1;
		else return findlength(3 * n + 1) + 1;
	}
	int intn = (int)n;
	if (chainlengths[intn] != -1) return chainlengths[intn];
	if (n % 2 == 0) {
		chainlengths[intn] = findlength(n / 2) + 1;
		return chainlengths[intn];
	}
	else {
		chainlengths[intn] = findlength(3 * n + 1) + 1;
		return chainlengths[intn];
	}
}

int main() {
	for (int i = 0; i < M; i++) chainlengths[i] = -1;
	chainlengths[1] = 1;
	int maxlen = 0;
	int index = 0;
	for (int i = 1; i < 1000000; i++) {
		int thislen = findlength(i);
		if (thislen > maxlen) {
			maxlen = thislen;
			index = i;
		}
	}
	cout << index << endl;
	return 0;
}