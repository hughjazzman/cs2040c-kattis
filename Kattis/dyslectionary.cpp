// CS2040/C Past Finals E

#include <string>		// string
#include <algorithm>	// sort
#include <vector>		// vector
#include <iostream>		// cout

using namespace std;

void sorts(vector<string> & v, unsigned int len) {
	sort(v.begin(), v.end());
	for (auto& x : v) {
		reverse(x.begin(), x.end());
		cout << string(len - x.size(), ' ') << x << '\n';
	}
	cout << '\n';
	v.clear();
}

void dys() {
	vector<string> v;
	string s;
	unsigned int len = 0;
	while (getline(cin, s)) {
		if (!s.empty()) {
			if (s.size() > len)
				len = s.size();
			reverse(s.begin(), s.end());
			v.push_back(s);
		}
		else {
			sorts(v, len);
			len = 0;
		}
	}
	sorts(v, len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dys();
    return 0;
}