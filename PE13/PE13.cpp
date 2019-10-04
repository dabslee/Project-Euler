#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "BigInteger.h"
using namespace std;

int main()
{
	ifstream sc ("PE13.txt");
	BigInteger intlist[100];
	for (int i = 0; i < 100; i++) {
		string readnum;
		getline(sc, readnum);
		BigInteger temp(readnum.substr(0, 50));
		intlist[i] = temp;
	}
	BigInteger mysum("0");
	for (BigInteger i : intlist) {
		mysum = mysum.add(i);
	}
	cout << mysum.toString().substr(0, 10) << endl;
	sc.close();
}