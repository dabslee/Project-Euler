#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

bool checkpal(int n) {
	string s = to_string(n);
	string s2 = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		s2 += s[i];
	}
	return s == s2;
}

int main() {
	int max = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			int n = i * j;
			if (checkpal(n) && n > max) {
				max = n;
			}
		}
	}
	cout << max << endl;
	return 0;
}