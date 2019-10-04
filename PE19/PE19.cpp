#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long ul;
typedef unsigned int ui;


ul CalcDayNumFromDate(ui y, ui m, ui d)
{
	m = (m + 9) % 12;
	y -= m / 10;
	ul dn = 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);

	return dn;
}

// ----------------------------------------------------------------------
// Given year, month, day, return the day of week (string).
// ----------------------------------------------------------------------
string CalcDayOfWeek(int y, ul m, ul d)
{
	string day[] = {
	  "Wednesday",
	  "Thursday",
	  "Friday",
	  "Saturday",
	  "Sunday",
	  "Monday",
	  "Tuesday"
	};

	ul dn = CalcDayNumFromDate(y, m, d);

	return day[dn % 7];
}

int main() {
	int numsuns = 0;
	for (ui year = 1901; year <= 2000; year++) {
		for (ui month = 1; month <= 12; month++) {
			string dow = CalcDayOfWeek(year, month, 1);
			if (dow == "Sunday") numsuns++;
		}
	}
	cout << numsuns << endl;
}