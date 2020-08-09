#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool comp(const string& s1, const string& s2) {
	if (s1[0] == s2[0])
		return s1[1] < s2[1];
	return s1[0] < s2[0];
}

void sos() {
	int n;
	
	while (cin >> n) {
		if (!n) return;
		vector<string> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		stable_sort(v.begin(), v.end(), comp);
		for (string s : v)
			cout << s << '\n';
		cout << '\n';
		v.clear();
	}	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sos();
    return 0;
}