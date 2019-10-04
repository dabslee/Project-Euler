#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
	int digits[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	sort(digits, digits + 9);
	set<int> myset;
	do {
		string perm = "";
		for (int i = 0; i < 9; i++) {
			perm += to_string(digits[i]);
		}
		for (int x = 0; x < 7; x++) {
			for (int e = x + 1; e < 8; e++) {
				int a = stoi(perm.substr(0, x + 1));
				int b = stoi(perm.substr(x + 1, e - x));
				int c = stoi(perm.substr(e + 1));
				if (a * b == c) {
					myset.insert(c);
				}
			}
		}
	} while (next_permutation(digits, digits + 9));
	int mysum = 0;
	for (int i : myset) {
		mysum += i;
	}
	cout << mysum << endl;
}