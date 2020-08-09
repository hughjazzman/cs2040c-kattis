#include <iostream>
#include <vector>		// vector
#include <utility>		// pair
#include <algorithm>	// max, min

using namespace std;

typedef pair<int, int> ii;

#define FOR(i,k) for(int i=0;i<k;i++)

void bungee() {
	int N, H;
	vector<int> v;
	cin >> N;

	FOR(i, N) {
		cin >> H;
		v.push_back(H);
	}

	int hi = 0, chi;
	vector<ii> LR(N, { -1,-1 });

	FOR(i, N - 1) {
		if (i == 0) continue;

		if (LR[i - 1].first >= v[i - 1])
			LR[i].first = LR[i - 1].first;
		else
			LR[i].first = v[i - 1];

		if (LR[N - i].second >= v[N - i])
			LR[N - 1 - i].second = LR[N - i].second;
		else
			LR[N - 1 - i].second = v[N - i];

	}

	FOR(i, N - 1) {
		chi = max(0, min(LR[i].first, LR[i].second) - v[i]);
		if (chi > hi)
			hi = chi;
	}
	

	cout << hi;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bungee();

    return 0;
}