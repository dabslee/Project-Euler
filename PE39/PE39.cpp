#include <iostream>
#include <array>
using namespace std;

int sumarr(int arr[3]) {
	return arr[0] + arr[1] + arr[2];
}

int main()
{
	int primitives[16][3] = { {3,4,5}, {5, 12, 13}, {8, 15, 17}, {7, 24, 25}, {20, 21, 29}, {12, 35, 37}, {9, 40, 41}, {28, 45, 53}, {11, 60, 61}, {33, 56, 65}, {16, 63, 65}, {48, 55, 73}, {36, 77, 85}, {13, 84, 85}, {39, 80, 89}, {65, 72, 97} };
	int perimeters[1000+1];
	for (int i = 0; i <= 1000; i++) {
		perimeters[i] = 0;
	}
	for (int i = 0; i < 16; i++) {
		int tcopy[3];
		for (int j = 0; j < 3; j++) {
			tcopy[j] = primitives[i][j];
		}
		while (sumarr(tcopy) <= 1000) {
			perimeters[sumarr(tcopy)] += 1;
			tcopy[0] += primitives[i][0];
			tcopy[1] += primitives[i][1];
			tcopy[2] += primitives[i][2];
		}
	}
	int maxvalue = 0;
	int maxindex = 0;
	for (int i = 0; i <= 1000; i++) {
		if (perimeters[i] > maxvalue) {
			maxvalue = perimeters[i];
			maxindex = i;
		}
	}
	cout << maxindex << endl;
}