#include "pch.h"
#include <iostream>
using namespace std;

long sumofsq(int n) {
	long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += pow(i, 2);
	}
	return sum;
}

int sqofsum(int n) {
	return pow((n + 1)*n / 2, 2);
}

int main()
{
	int n = 100;
	cout << abs(sumofsq(n) - sqofsum(n)) << endl;
	return 0;
}