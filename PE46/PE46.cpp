#include <iostream>
#include <vector>
using namespace std;

bool isprime(int n) {
	if (n < 2) return false;
	if (n < 4) return true;
	for (int i = 2; i < (int)pow(n, 0.5) + 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	vector<long> primes;
	vector<long> twicesquares;
	for (int i = 2; i < 10000; i++) {
		if (isprime(i)) primes.push_back(i);
	}
	for (int i = 1; i < 100; i++) {
		twicesquares.push_back(2 * i * i);
	}

	bool array[30000];
	for (int i = 0; i < 30000; i++) {
		array[i] = false;
	}
	for (long p : primes) {
		for (long t : twicesquares) {
			array[p + t] = true;
		}
	}
	for (long i = 1; i < 100000000; i++) {
		if (!(isprime(2 * i + 1))) {
			if (!(array[2 * i + 1])) {
				cout << (2 * i + 1) << endl;
				return 0;
			}
		}
	}
	return 0;
}