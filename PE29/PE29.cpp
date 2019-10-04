#include "pch.h"
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<double> myset;

	for (int a = 2; a <= 100; a++) {
		for (int b = 2; b <= 100; b++) {
			myset.insert(pow(a, b)); // Rounding error when I use Integer class for set
		}
	}

	cout << myset.size() << endl;
}