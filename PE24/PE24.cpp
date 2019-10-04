// PE24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> permutation(vector<int> lst) {
	if (lst.size() == 0) {
		vector<vector<int>> empty;
		return empty;
	}
	if (lst.size() == 1) {
		vector<vector<int>> mylist;
		mylist.push_back(lst);
		return mylist;
	}
	vector<vector<int>> l;

	for (size_t i = 0; i < lst.size(); i++) {
		int m = lst[i];
		vector<int> remLst (&lst[0], &lst[i]);
		remLst.insert(remLst.end(), lst.begin() + i + 1, lst.end());
		for (vector<int> p : permutation(remLst)) {
			vector<int> mcopy;
			mcopy.push_back(m);
			mcopy.insert(mcopy.end(), p.begin(), p.end());
			l.push_back(mcopy);
		}
	}
	return l;
}

int main() {
	vector<int> digits;
	for (int i = 0; i < 10; i++) digits.push_back(i);
	vector<vector<int>> permutations = permutation(digits);
	vector<string> permstr;
	for (vector<int> a : permutations) {
		string mystr = "";
		for (int i : a) mystr += to_string(i);
		permstr.push_back(mystr);
	}
	sort(permstr.begin(), permstr.end());
	cout << permstr[1000000 - 1] << endl;
}