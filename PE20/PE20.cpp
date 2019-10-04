#include "pch.h"
#include <iostream>
#include <string>
#include "BigInteger.h"
using namespace std;

int main()
{
	BigInteger fac("1");

	for (int i = 1; i <= 100; i++) {
		fac = fac.multiply(BigInteger::valueOf(i));
	}

	int mysum = 0;
	string facstr = fac.toString();
	for (char c : facstr) {
		mysum += c - '0';
	}

	cout << mysum << endl;
}