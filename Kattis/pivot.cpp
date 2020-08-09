#include <iostream>
#include <vector>
#include <utility>	// pair
#include <climits>
#include <algorithm> // min, max

using namespace std;

typedef pair<int, int> ii;

#define FOR(i,k) for(int i=0;i<k;i++)

void pivot() {
	int n, a, t = 0;
	vector<int> v;
	cin >> n;
	vector<ii> LR(n, { INT_MIN, INT_MAX });

	// parse
	FOR(i, n) {
		cin >> a;
		v.push_back(a);
	}

	// running min/max
	FOR(i, n) {
		if (i == 0) continue;

		LR[i].first = max(LR[i - 1].first, v[i - 1]);
		LR[n - i - 1].second = min(LR[n - i].second, v[n - i]);
	}

	// count suitable pivots
	FOR(i, n) {
		if (LR[i].first <= v[i] && LR[i].second > v[i])
			t++;
	}

	cout << t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pivot();
    return 0;
}