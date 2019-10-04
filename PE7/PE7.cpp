#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

bool isprime(int n) {
	if (n < 2) {
		return false;
	}
	bool is = true;
	for (int i = 2; i <= (int)pow(n, 0.5); i++) {
		if (n % i == 0) is = false;
	}
	return is;
}

int main()
{
	int count = 0;
	int i = 1;
	while (count < 10001) { // third prime
		i++;
		if (isprime(i)) count++;
	}
	cout << i << endl;
	return 0;
}