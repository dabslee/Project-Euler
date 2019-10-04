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
	BigInteger add(BigInteger b);
private:
	string svalue;
};