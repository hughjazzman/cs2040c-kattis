#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void cab() {
	int n, p, m;
	bool w = false;
	string s;
	unordered_map<string, int> mp;
	cin >> n >> p >> m;
	while (n--) {
		cin >> s;
		mp[s] = 0;
	}

	while (m--) {
		cin >> s >> n;
		int sp = mp[s];
		if (sp >= p) continue;
		sp += n;
		mp[s] = sp;
		if (sp >= p) {
			w = true;
			cout << s << " wins!\n";
		}
			
	}
	if (!w) cout << "No winner!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cab();
    return 0;
}