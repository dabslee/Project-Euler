#include <iostream>
#include <string>
using namespace std;

int main()
{
	int myprod = 1;
	int numdigits = 0;
	int nextnum = 0;
	for (int i = 0; i < 7; i++) {
		while (numdigits < pow(10, i)) {
			numdigits += to_string(nextnum).length();
			nextnum++;
		}
		myprod *= to_string(nextnum)[numdigits - (int)pow(10, i)] - '0';
	}
	cout << myprod << endl;
}