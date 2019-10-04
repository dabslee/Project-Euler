#include "pch.h"
#include <iostream>
#include <fstream>;
#include <vector>;
using namespace std;

int main()
{
	// get input
	fstream sc ("PE18.txt");
	vector<vector<int>> input;

	int depth = 1;
	int inputint = 0;
	while (sc.peek()!=EOF) {
		vector<int> oneline;
		for (int i = 0; i < depth; i++) {
			sc >> inputint;
			oneline.push_back(inputint);
		}
		input.push_back(oneline);
		depth++;
	}
	depth--;

	// create matrix of max sums
	int** sums;
	sums = new int*[depth];
	for (int i = 0; i < depth; i++) {
		sums[i] = new int[depth + 1];
	}
	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < depth + 1; j++) {
			sums[i][j] = 0;
		}
	}
	sums[0][1] = input[0][0];
	for (int i = 1; i < depth; i++) {
		for (int j = 1; j <= i + 1; j++) {
			int a = sums[i - 1][j - 1] + input[i][j-1];
			int b = sums[i - 1][j] + input[i][j - 1];
			sums[i][j] = a > b ? a : b; // max wasn't working here for some reason :(
		}
	}

	// check for maximum sum in the bottom-most row
	int maxsum = 0;
	for (int i = 0; i < depth + 1; i++) {
		if (sums[depth - 1][i] > maxsum) maxsum = sums[depth - 1][i];
	}
	cout << maxsum << endl;

	sc.close();
}