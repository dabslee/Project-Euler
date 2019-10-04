/*
Let's take this chance to create a class 'Factorization.cpp' that just stores a variety of
methods related to factorization, i.e. isprime, primefac, numdivisors
*/

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int sumdiv(int n) {
	int mysum = 0;
	for (int f = 1; f <= (int)sqrt(n); f++) {
		if (n % f == 0) mysum += f + n / f;
	}
	if (sqrt(n) == (int)sqrt(n)) return mysum -= (int)sqrt(n);
	return mysum - n;
}

int main()
{
	vector<int> proper;
	for (int i = 2; i < 10000; i++) {
		int j = sumdiv(i);
		if (find(proper.begin(), proper.end(), j)!=proper.end() || i == j) continue;
		if (i == sumdiv(j)) {
			proper.push_back(i); proper.push_back(j);
		}
	}
	int sum = 0;
	for (int i : proper) sum += i;
	cout << sum << endl;
}
