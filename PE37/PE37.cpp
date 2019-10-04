#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n < 4) return true;
	for (int i = 2; i < (int)pow(n, 0.5) + 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int truncateleft(int n) {
	if (n > 9) return stoi(to_string(n).substr(1));
	return 0;
}

int truncateright(int n) {
	return n / 10;
}

bool checkleft(int n) {
	while (n != 0) {
		if (!isPrime(n)) {
			return false;
		}
		n = truncateleft(n);
	}
	return true;
}

bool checkright(int n) {
	while (n != 0) {
		if (!isPrime(n)) {
			return false;
		}
		n = truncateright(n);
	}
	return true;
}

int main() {
	int count = 0;
	int mysum = 0;
	int i = 9;
	while (count < 11) {
		i++;
		if (checkleft(i) && checkright(i)) {
			count++;
			mysum += i;
		}
	}
	cout << mysum << endl;
}