#include <stdio.h>
#include <stdint.h>
#include <iostream>
using namespace std;

#define MAXLEN 1000
#define MAXSUM 25

void scanList(int lst[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
}

int closestSum(int lst[], int n, int num) {
	int closestSum = lst[0] + lst[1], diff = abs(num - closestSum);
	int temp, tempDiff;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp = lst[i] + lst[j];
			tempDiff = abs(num - temp);
			if (tempDiff < diff) {
				closestSum = temp;
				diff = tempDiff;
			}
		}
	}
	return closestSum;
}

void findSums(int numLst[], int sumLst[], int n, int m) {
	for (int i = 0; i < m; i++) {
		cout << "Closest sum to " << sumLst[i] << " is " << closestSum(numLst, n, sumLst[i]) << "." << endl;
	}
}

int main() {
	int n, m, numLst[MAXLEN], sumLst[MAXSUM], count = 1;
	while (cin >> n) {
		scanList(numLst, n);
		cin >> m;
		scanList(sumLst, m);
		cout << "Case " << count << ":" << endl;
		findSums(numLst, sumLst, n, m);
		count++;
	}
}