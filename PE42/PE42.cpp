#include <iostream>
#include <string>
using namespace std;

bool checkpan(int n) {
	string nstr = to_string(n);
	int ndigits = nstr.length();
	for (int i = 1; i < ndigits + 1; i++) {
		// s1.find(s2) != std::string::npos
		if (nstr.find(to_string(i)) == string::npos) {
			return false;
		}
	}
	return true;
}

bool checkprime(int n) {
	if (n < 2) return false;
	if (n < 4) return true;
	for (int i = 2; i < (int)pow(n, 0.5) + 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int mymax = 0;
	for (int i = 1; i < 10000000; i++) {
		if (checkpan(i) && checkprime(i)) {
			mymax = i;
		}
	}
	cout << mymax << endl;
}