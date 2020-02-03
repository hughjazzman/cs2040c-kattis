#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int transform(int n) {
	int res = 2 * n;
	if (res > 9) {
		res %= 10;
		res++;
	}
	return res;
}


void check(string m) {
	int res = 0, nlen = m.length(), d;
	for (int i = 0; i < nlen; i++) {
		d = m[nlen - i - 1] - '0';
		if (i % 2)
			res += transform(d);
		else
			res += d;
	}
	if (res % 10) cout << "FAIL" << endl;
	else cout << "PASS" << endl;
}

int main() {
	int n;
	string m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		check(m);
	}
	return 0;
}