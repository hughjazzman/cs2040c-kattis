#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

#define MAXLEN 101

void shorten(char str[]) {
	int i = 0;
	cout << str[i];
	while (str[i]) {
		if (str[i] == '-')
			cout << str[i+1];
		i++;
	}
	cout << endl;
}

int main() {
	char str[MAXLEN];
	cin.getline(str, MAXLEN);
	shorten(str);
}