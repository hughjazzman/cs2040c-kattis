#include <iostream>
#include <string>

using namespace std;

void line() {
	int n;
	bool inc = true, dec = true;
	string s1, s2;
	cin >> n >> s2;
	while (--n) {
		cin >> s1;
		inc &= s1 > s2;
		dec &= s1 < s2;
		if (!(inc || dec)) break;
		s2 = s1;
	}

	if (inc)
		cout << "INCREASING";
	else if (dec)
		cout << "DECREASING";
	else
		cout << "NEITHER";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    line();
    return 0;
}