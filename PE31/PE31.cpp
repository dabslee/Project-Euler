#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int poss[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	int dynamic[201];
	for (int i = 0; i < 201; i++) {
		dynamic[i] = 0;
	}
	dynamic[0] = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = poss[i]; j < 201; j++) {
			dynamic[j] += dynamic[j - poss[i]];
		}
	}

	cout << dynamic[200] << endl;
}