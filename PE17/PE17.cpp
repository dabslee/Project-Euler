#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

string ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string twodigit(int n) {
	if (n < 10) return ones[n];
	if (n < 20) return teens[n - 10];
	return tens[n / 10] + ones[n % 10];
}

string threedigit(int n) {
	if (n < 100) return twodigit(n);
	if (n == 1000) return "onethousand";
	if (n % 100 != 0) return ones[n / 100] + "hundredand" + twodigit(n % 100);
	return ones[n / 100] + "hundred";
}

int main() {
	int mysum = 0;
	for (int i = 1; i <= 1000; i++) {
		mysum += threedigit(i).length();
	}
	cout << mysum << endl;
}