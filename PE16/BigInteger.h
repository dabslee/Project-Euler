#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
A version of Java's BigInteger adapted for C++. Currently only has add method.
*/

class BigInteger {
public:
	BigInteger();
	BigInteger(string svalue);

	string toString();
	int intValue();

	BigInteger add(BigInteger b);
	BigInteger subtract(BigInteger b);
	BigInteger multiply(BigInteger b);
	BigInteger divide(BigInteger b);
	BigInteger pow(int e);
	int compare(BigInteger b);

	static BigInteger valueOf(int n);
private:
	string svalue;
	BigInteger subtract_byone();
	BigInteger divide_byint(int d);
};