#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "BigInteger.h"
using namespace std;

BigInteger::BigInteger() {
	svalue = "0";
}

BigInteger::BigInteger(string s) {
	svalue = s;
}

string BigInteger::toString() {
	return svalue;
}

BigInteger BigInteger::add(BigInteger b) {
	string as = svalue;
	string bs = b.toString();
	string c = ""; // as + bs = c
	int co = 0; // for holding carry-over values

	// equalize as and bs string lengths
	if (as.length() > bs.length()) {
		while (as.length() != bs.length()) {
			bs = "0" + bs;
		}
	}
	else {
		while (as.length() != bs.length()) {
			as = "0" + as;
		}
	}

	for (int i = as.length() - 1; i >= 0; i--) {
		int digita = as[i] - '0';
		int digitb = bs[i] - '0';
		// no carry over case
		if (digita + digitb + co < 10) {
			c = to_string(digita + digitb + co) + c;
			co = 0;
		}
		else { // carry over case
			c = to_string((digita + digitb + co) % 10) + c;
			co = (digita + digitb + co) / 10;
		}
	}
	// check if there's one last carry over to do
	if (co != 0) c = to_string(co) + c;
	BigInteger returnb(c);
	return returnb;
}