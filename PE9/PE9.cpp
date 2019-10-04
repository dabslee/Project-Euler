#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	for (int a = 1; a < 1000; a++) {
		for (int b = 1; b <= a; b++) {
			int csq = a * a + b * b;
			if (sqrt(csq) == (int)sqrt(csq) && a + b + sqrt(csq) == 1000) {
				cout << a * b * (int)sqrt(csq) << endl;
				return 0;
			}
		}
	}
}