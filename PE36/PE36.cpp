#include <iostream>
#include <string>
#include <bitset>
using namespace std;

unsigned long long toib2(int n) {
	string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return stoull(r);
}

bool checkpalin(unsigned long long i) {
	string str = to_string(i);
	reverse(str.begin(), str.end());
	return to_string(i) == str;
}

bool check10(int ib10) {
	return checkpalin(ib10);
}

bool check2(int ib10) {
	return checkpalin(toib2(ib10));
}

int main() {
	int mysum = 0;
	for (int i = 1; i < 1000000; i++) {
		if (i == 312) {
			int temp = 0;
		}
		if (check10(i) && check2(i)) {
			mysum += i;
		}
	}
	cout << mysum << endl;
	return 0;
}