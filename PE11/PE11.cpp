#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 20;
const int LEN = 4;
void printarr(string arr[SIZE]);
// The following function (pre-dec) return product in direction, or -1 if undef.
int product(int matrix[SIZE][SIZE], int len, int i0, int j0, int di, int dj);

void split(string s, string d, string sarr[SIZE]) { // s = string to split, d = delimiter, sarr = split array
	for (int i = 0; i < SIZE; i++) {
		sarr[i] = s.substr(0, s.find(d));
		s = s.substr(s.find(d) + d.length(), s.length() - s.find(d) - d.length());
	}
}

void getinput(int matrix[SIZE][SIZE]) {
	string line;
	ifstream myfile("PE11.txt");
	if (myfile.is_open()) {
		int j = 0;
		while (getline(myfile, line)) {
			string linearr[SIZE];
			split(line, " ", linearr);
			for (int i = 0; i < SIZE; i++) {
				matrix[j][i] = stoi(linearr[i]);
			}
			j++;
		}
		myfile.close();
	}
}

int main()
{
	int maxim = 0;
	int matrix[SIZE][SIZE];
	getinput(matrix);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int di = -1; di <= 1; di++) {
				for (int dj = -1; dj <= 1; dj++) {
					if (!(di == 0 && dj == 0)) {
						int testprod = product(matrix, LEN, i, j, di, dj);
						maxim = testprod > maxim ? testprod : maxim;
					}
				}
			}
		}
	}
	cout << maxim << endl;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printarr(string arr[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "/";
	}
}

int product(int matrix[SIZE][SIZE], int len, int i0, int j0, int di, int dj){ // smallest it would return is 1.
	int s = 1;
	int num = 0;
	while (num < len) {
		int newi = i0 + di * num;
		int newj = j0 + dj * num;
		if (newi > 0 && newi < SIZE && newj > 0 && newj < SIZE) {
			s *= matrix[i0 + di * num][j0 + dj * num];
		}
		num++;
	}
	return s;
}