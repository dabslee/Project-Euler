
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int f = 1;
	int fp = 1;
	int s = 0;
	while (f <= 4000000) {
		if (f % 2 == 0) {
			s += f;
		}
		int temp = f;
		f += fp;
		fp = temp;
	}
	cout << s << endl;
}
