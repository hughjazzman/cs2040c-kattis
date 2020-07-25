#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>


using namespace std;

typedef long long ll;

#define FOR(i,k) for(int i=0;i<k;i++)


void p2() {
	int N, t, m;
	ll r = 0;
	vector<int> v;
	unordered_set<int> s;
	unordered_map<int, int> mp;

	cin >> N >> t;

	switch (t) {
	case 1: {
		while (N--) {
			cin >> m;
			if (s.count(7777 - m)) {
				cout << "Yes";
				return;
			}
			s.insert(m);
		}
		cout << "No";
		break;
	}
	case 2: {
		while (N--) {
			cin >> m;
			if (s.count(m)) {
				cout << "Contains duplicate";
				return;
			}
			s.insert(m);
		}
		cout << "Unique";
		break;
	}
	case 3: {
		FOR(i, N) {
			cin >> m;
			if (mp.count(m)) {
				mp[m]++;
				if (mp[m] > N / 2) {
					cout << m;
					return;
				}
			}
			mp.insert({ m,1 });
		}
		cout << -1;
		break;
	}
	case 4: {
		FOR(i, N) {
			cin >> m;
			v.push_back(m);
		}
		sort(v.begin(), v.end());
		if (N % 2)
			cout << v[(N - 1) / 2];
		else
			cout << v[(N / 2) - 1] << ' ' << v[N / 2];
		break;
	}
	case 5: {
		while (N--) {
			cin >> m;
			if (m >= 100 && m <= 999)
				v.push_back(m);
		}
		sort(v.begin(), v.end());
		for (int i : v)
			cout << i << ' ';
		break;
	}

	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p2();

    return 0;
}