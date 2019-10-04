#include "pch.h"
#include <iostream>
using namespace std;

bool isPrime(long n) {
	if (n < 2) return false;
	if (n < 4) return true;
	for (int f = 2; f <= (int)pow(n, 0.5); f++) {
		if (n % f == 0) return false;
	}
	return true;
}

int main()
{
	unsigned long long n = 600851475143;
	unsigned long long maxi = 0;
	unsigned long long i = 2;
	while (i <= n) {
		if (n % i == 0 && isPrime(i)) {
			maxi = i;
			n /= i;
		}
		i++;
	}
	cout << maxi << endl;
}
