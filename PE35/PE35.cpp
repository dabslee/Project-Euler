#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n < 4) return true;
	if (n == 4) return false;
	if (n == 5) return true;
	for (int i = 2; i < (int)pow(n, 0.5) + 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

string shiftleft(string sn) {
	string shifted = sn.substr(1);
	shifted += sn[0];
	return shifted;
}

bool checkcirc(string sn) {
	if (!isPrime(stoi(sn))) return false;
	string sn2 = shiftleft(sn);
	while (sn2 != sn) {
		if (!isPrime(stoi(sn2))) return false;
		sn2 = shiftleft(sn2);
	}
	return true;
}

int main() {
	int count = 0;
	for (int i = 2; i < 1000000; i++) {
		if (checkcirc(to_string(i))) count++;
	}
	cout << count << endl;

	return 0;
}