#include "pch.h"
#include <iostream>
#include "BigInteger.h"

using namespace std;

BigInteger factorial(int n) {
	BigInteger prod("1");
	for (int i = 1; i <= n; i++) {
		prod = prod.multiply(BigInteger::valueOf(i));
	}
	return prod;
}

BigInteger ncr(int n, int r) {
	if (r > n - r) {
		return ncr(n, n - r);
	}
	BigInteger prod("1");
	for (int i = r+1; i <= n; i++) {
		prod = prod.multiply(BigInteger::valueOf(i));
	}
	return prod.divide(factorial(n - r));
}

int main() {
	int size = 20;
	cout << (ncr(size * 2, size)).toString() << endl;
}