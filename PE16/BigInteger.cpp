#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "BigInteger.h"
#include <vector>
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

int BigInteger::intValue() {
	return stoi(svalue);
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

// only works when solution ends up positive
BigInteger BigInteger::subtract(BigInteger b)
{
	string str1 = this->toString();
	string str2 = b.toString();

	// Before proceeding further, make sure str1 
	// is not smaller 
	if (this->compare(b) == -1)
		swap(str1, str2);

	// Take an empty string for storing result 
	string str = "";

	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings 
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	// Run loop till small string length 
	// and subtract digit of str1 to str2 
	for (int i = 0; i < n2; i++)
	{
		// Do school mathematics, compute difference of 
		// current digits 

		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

		// If subtraction is less then zero 
		// we add then we add 10 into sub and 
		// take carry as 1 for calculating next step 
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number 
	for (int i = n2; i < n1; i++)
	{
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive 
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// reverse resultant string 
	reverse(str.begin(), str.end());

	BigInteger ans(str);
	return ans;
}

BigInteger BigInteger::multiply(BigInteger b) {
	string num1 = this->toString();
	string num2 = b.toString();
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0)
		return BigInteger("0");

	// will keep the result number in vector 
	// in reverse order 
	vector<int> result(n1 + n2, 0);

	// Below two indexes are used to find positions 
	// in result.  
	int i_n1 = 0;
	int i_n2 = 0;

	// Go from right to left in num1 
	for (int i = n1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every 
		// multiplication of a digit in num2 
		i_n2 = 0;

		// Go from right to left in num2              
		for (int j = n2 - 1; j >= 0; j--)
		{
			// Take current digit of second number 
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number 
			// and add result to previously stored result 
			// at current position.  
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration 
			carry = sum / 10;

			// Store result 
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell 
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every 
		// multiplication of a digit in num1. 
		i_n1++;
	}

	// ignore '0's from the right 
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or 
	// one of num1 or num2 were '0' 
	if (i == -1)
		return BigInteger("0");

	// generate the result string 
	string s = "";

	while (i >= 0)
		s += std::to_string(result[i--]);

	return BigInteger(s);
}

BigInteger BigInteger::divide(BigInteger b) {
	try {
		return divide_byint(b.intValue());
	}
	catch (const out_of_range& e) {}

	if (this->compare(b) == -1) return BigInteger("0");
	if (this->compare(b) == 0) return BigInteger("1");
	if (this->compare(b.multiply(BigInteger("2"))) == -1) return BigInteger("1");

	// binary search for quotient
	BigInteger upperbound(this->toString());
	BigInteger lowerbound("0");
	while (upperbound.subtract(lowerbound).compare(BigInteger("1")) == 1) { // while upperbound-lowerbound > 1
		BigInteger middle = upperbound.add(lowerbound).divide_byint(2);
		if (this->compare(middle.multiply(b)) == 0) {
			return middle;
		}
		else if (this->compare(middle.multiply(b)) == -1) {
			upperbound = middle;
		}
		else if (this->compare(middle.multiply(b)) == 1) {
			lowerbound = middle;
		}
	}
	return lowerbound;
}

BigInteger BigInteger::pow(int e) {
	BigInteger ans("1");
	BigInteger thiscopy(this->toString());
	for (int i = 0; i < e; i++) {
		ans = ans.multiply(thiscopy);
	}
	return ans;
}

// returns -1 if smaller, 0 if equal, 1 if bigger
int BigInteger::compare(BigInteger b) {
	if (svalue.length() > b.toString().length()) {
		return 1;
	}
	else if (svalue.length() < b.toString().length()) {
		return -1;
	}
	// compare each digit from the first one to the last one.
	int i = 0;
	while (svalue[i] == b.toString()[i]) {
		i++;
		if (i >= svalue.length()) {
			return 0;
		}
	}
	if (svalue[i] > b.toString()[i]) return 1;
	return -1;
}

BigInteger BigInteger::valueOf(int n) {
	BigInteger b(to_string(n));
	return b;
}

// following only works for positive numbers
BigInteger BigInteger::subtract_byone() {
	string bstring = svalue;
	if (bstring[bstring.length() - 1] != '0') {
		bstring[bstring.length() - 1] = bstring[bstring.length() - 1] - 1;
		BigInteger retvalue(bstring);
		return retvalue;
	}
	// last digit is 0 case
	// find the lastmost digit that is not 0
	// change that digit by -1, then change all following digits to 9
	int i = bstring.length() - 1;
	while (bstring[i] == '0') i--;
	bstring[i] = bstring[i] - 1;
	for (int j = i + 1; j < bstring.length(); j++) {
		bstring[j] = '9';
	}
	BigInteger retvalue(bstring);
	return retvalue;
}

BigInteger BigInteger::divide_byint(int d) {
	string number = this->toString();

	// As result can be very large store it in string 
	string ans;

	// Find prefix of number that is larger 
	// than divisor. 
	int idx = 0;
	int temp = number[idx] - '0';
	while (temp < d)
		temp = temp * 10 + (number[++idx] - '0');

	// Repeatedly divide divisor with temp. After  
	// every division, update temp to include one  
	// more digit. 
	while (number.size() > idx)
	{
		// Store result in answer i.e. temp / divisor 
		ans += (temp / d) + '0';

		// Take next digit of number 
		temp = (temp % d) * 10 + number[++idx] - '0';
	}

	// If divisor is greater than number 
	if (ans.length() == 0)
		return BigInteger("0");

	// else return ans 
	return BigInteger(ans);
}