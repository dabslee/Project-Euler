// PE22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> elems;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

int strval(string s) {
	int val = 0;
	for (char c : s) val += c - 'A' + 1;
	return val;
}
int main() {
	ifstream f ("names.txt");
	string line; getline(f, line);
	vector<string> fcomma = split(line, ',');
	f.close();

	vector<string> mylist;
	for (string s : fcomma) {
		mylist.push_back(s.substr(1, s.length() - 2));
	}
	sort(mylist.begin(), mylist.end());

	int mysum = 0;
	int i = 1;
	for (string s : mylist) {
		mysum += i * strval(s);
		i++;
	}

	cout << mysum << endl;
}