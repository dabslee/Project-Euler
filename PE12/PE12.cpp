#include "pch.h"
#include <iostream>
using namespace std;

int numfac(int n) {
	// Square case
	if (sqrt(n) == (int)sqrt(n)) {
		int num = 0;
		for (int i = 1; i < (int)sqrt(n); i++) {
			if (n % i == 0) num += 2;
		}
		num++;
		return num;
	}
	int num = 0;
	for (int i = 1; i < (int)sqrt(n) + 1; i++) {
		if (n % i == 0) num += 2;
	}
	return num;
}

int main()
{
	int n = 1;
	while (numfac(n*(n + 1) / 2) <= 500) n++;
	cout << (n*(n + 1) / 2) << endl;
}