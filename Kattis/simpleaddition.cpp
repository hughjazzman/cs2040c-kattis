#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string add(string n1, string n2) {
	int len1, len2, diff, sum, carry = 0;
	string res = "";

	if (n1.length() > n2.length())
		swap(n1, n2);

	len1 = n1.length();
	len2 = n2.length();
	diff = len2 - len1;

	for (int i = len1 - 1; i >= 0; i--) {
		sum = n1[i] - '0' + n2[i+diff] - '0' + carry;
		carry = sum / 10;
		res.push_back(sum%10 + '0');
	}

	for (int i = diff - 1; i >= 0; i--) {
		sum = n2[i] - '0' + carry;
		carry = sum / 10;
		res.push_back(sum % 10 + '0');
	}

	if (carry)
		res.push_back(carry + '0');

	reverse(res.begin(), res.end());

	return res;
}


int main() {
	string n1, n2;
	cin >> n1 >> n2;
	cout << add(n1, n2);
	return 0;
}