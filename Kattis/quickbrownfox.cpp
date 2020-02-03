#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 101

// Convert char to int, 0-25 valid, -1 invalid
int cToi(char n) {
	int lowC = n - 'a', upC = n - 'A';
	if (lowC >= 0 && lowC < 26)
		return lowC;
	else if (upC >= 0 && upC < 26)
		return upC;
	else
		return -1;
}

void valid(char str[], int arr[]) {
	int i = 0, letterNum;
	while (str[i]) {
		letterNum = cToi(str[i]);
		if (letterNum >= 0)
			arr[letterNum] = 1;
		i++;
	}
	

}

void result(int arr[]) {
	int pangram = 1;
	for (int j = 0; j < 26; j++) {
		if (!arr[j]) {
			if (pangram) {
				pangram = 0;
				cout << "missing ";
			}
			cout << (char)(j + 'a');
		}
	}
	if (pangram)
		cout << "pangram";
	cout << endl;
}


int main() {
	int n;
	char str[MAXLEN];
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int arr[26] = { 0 };
		cin.getline(str, MAXLEN);
		valid(str, arr);
		result(arr);
	}
}