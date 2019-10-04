#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
	int prod = 1;
	for (int i = 1; i <= n; i++) {
		prod *= i;
	}
	return prod;
}

int sumfac(int n) {
	int mysum = 0;
	for (char c : to_string(n)) {
		mysum += factorial(c - '0');
	}
	return mysum;
}

bool check(int n) {
	return sumfac(n) == n;
}

int main()
{
	int mysum = 0;
	for (int i = 3; i < 100000; i++) {
		if (check(i)) mysum += i;
	}
	cout << mysum << endl;
}