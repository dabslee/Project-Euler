#include "pch.h"
#include <iostream>
#include "BigInteger.h"
using namespace std;

int main()
{
	int mysum = 0;
	string mystring = (BigInteger("2")).pow(1000).toString();
	for (char c : mystring) {
		mysum += c - '0';
	}
	cout << mysum << endl;
}