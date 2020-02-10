#include <iostream>
#include <string>

using namespace std;


void special(string &s, string &res, char &c, int *idx) {
	if (c == '<' && *idx) {
		if (*idx == -1)
			res.pop_back();
		else {
			res.erase(res.begin() + *idx - 1);
			(*idx)--;
		}
	}
	else if (c == ']')
		*idx = -1;
	else if (c == '[')
		*idx = 0;
}

void decode() {
	string s, res;
	char c;
	int idx = 0;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		c = s[i];
		if (c == '<' || c == ']' || c == '[')
			special(s, res, c, &idx);
		else if (idx < 0)
			res.push_back(c);
		else {
			res.insert(res.begin() + idx, c);
			idx++;
		}
	}

	cout << res << '\n';
	
}

void sim() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		decode();
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sim();
    return 0;
}