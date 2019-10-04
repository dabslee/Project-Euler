#include "pch.h"
#include <iostream>
using namespace std;

bool isprime(int n) {
	if (n > 1 && n < 4) return true;
	for (int f = 2; f <= (int)sqrt(n); f++) {
		if (n % f == 0) return false;
	}
	return true;
}

int main()
{
	unsigned long long mysum = 2;
	//cout << mysum << endl;
	int upto = 2000000;
	for (int i = 3; i < upto; i += 2) {
		if (isprime(i)) {
			mysum += i;
			//cout << i << endl;
		}
	}
	cout << mysum << endl;
	return 0;
}