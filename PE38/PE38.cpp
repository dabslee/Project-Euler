#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkpan(string nstr) {
	if (nstr.length() != 9) return false;
	for (int i = 1; i < 10; i++) {
		if (nstr.find(to_string(i)) == string::npos) return false;
	}
	return true;
}

int main() {
	int mymax = 0;
	for (int i = 0; i < 10000; i++) {
		for (int n = 1; n < 10; n++) {
			string concated = "";
			for (int j = 1; j < n + 1; j++) {
				concated += to_string(i * j);
			}
			if (checkpan(concated)) {
				mymax = max(stoi(concated), mymax);
			}
		}
	}

	cout << mymax << endl;
}