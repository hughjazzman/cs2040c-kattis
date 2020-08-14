#include <iostream>
#include <string>
#include <vector>

using namespace std;


void sm() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		int i = 1;
		while (i * i < s.size())
			i++;
		string pad(i * i - s.size(), '*');
		s.append(pad);
		for (int j = 0; j < i; j++) {
			for (int k = i - 1; k >= 0; k--) {
				if (s[k * i + j] != '*')
					cout << s[k * i + j];
			}
		}
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sm();
    return 0;
}