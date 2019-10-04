#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	// Everything divides 0  
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	// base case 
	if (a == b)
		return a;

	// a is greater 
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

int main()
{
	vector<int> fracs_n;
	vector<int> fracs_d;

	// ab/cd
	for (int a = 1; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 1; c < 10; c++) {
				for (int d = 0; d < 10; d++) {
					if (10 * a + b > 10 * c + d || 10 * a + b == 10 * c + d) continue;
					if (b == 0 && d == 0) continue;
					if (gcd(10 * a + b, 10 * c + d) == 1) continue;
					if (a == c) {
						if (d == 0 || 1.0 * b / d != 1.0 * (10 * a + b) / (10 * c + d)) continue;
					}
					else if (a == d) {
						if (1.0 * b / c != 1.0 * (10 * a + b) / (10 * c + d)) continue;
					}
					else if (b == c) {
						if (d == 0 || 1.0 * a / d != 1.0 * (10 * a + b) / (10 * c + d)) continue;
					}
					else if (b == d) {
						if (1.0 * a / c != 1.0 * (10 * a + b) / (10 * c + d)) continue;
					}
					else continue;
					fracs_n.push_back(10 * a + b);
					fracs_d.push_back(10 * c + d);
				}
			}
		}
	}

	int numer = 1;
	for (int n : fracs_n) numer *= n;
	int denom = 1;
	for (int d : fracs_d) denom *= d;
	cout << denom / gcd(numer, denom) << endl;
}