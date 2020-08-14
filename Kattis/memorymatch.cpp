#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void mem() {
	int n, k, c1, c2, fullPair = 0, halfPair = 0;
	string p1, p2;
	cin >> n >> k;
	vector<bool> v(n, false);
	map<string, int> mp;
	while (k--) {
		cin >> c1 >> c2 >> p1 >> p2;
		--c1; --c2;
		if (p1 == p2) {
			n -= 2;
			if (v[c1] && v[c2])
				fullPair--;
			else if (v[c1] || v[c2])
				halfPair--;
			continue;
		}
		if (mp.count(p1) && mp[p1] != c1 && !(v[c1] && v[mp[p1]])) {
			fullPair++;
			halfPair--;
		}
		else if (!mp.count(p1))
			halfPair++;
		if (mp.count(p2) && mp[p2] != c2 && !(v[mp[p2]] && v[c2])) {
			fullPair++;
			halfPair--;
		}
		else if (!mp.count(p2))
			halfPair++;

		v[c1] = true;
		v[c2] = true;
		mp[p1] = c1;
		mp[p2] = c2;
	}
	if (n - 2*fullPair<= 2*halfPair)
		fullPair += halfPair ;
		
	if (n - 2 * fullPair == 2)
		fullPair++;
	cout << fullPair;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    mem();
    return 0;
}