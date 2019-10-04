// PE25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BigInteger.h"
using namespace std;

int main()
{
	BigInteger f("1");
	int i = 1;
	BigInteger fp("0");

	while (f.toString().length() < 1000) {
		i++;
		BigInteger temp = f;
		f = fp.add(f);
		fp = temp;
	}

	cout << i << endl;
}