#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define FOR(i,k) for(int i=0;i<k;i++)

void cow() {
	ll C, N, M, ci, dj;
	cin >> C >> N >> M;
	vector<ll> farms, days, num_farms, new_farms;

	while (N--) {
		cin >> ci;
		farms.push_back(ci);
	}

	while (M--) {
		cin >> dj;
		days.push_back(dj);
	}

	int lastDay = *max_element(days.begin(), days.end());
	int new_farm_cows;
	bool all_double = false;
	num_farms.push_back(farms.size());

	FOR(i, lastDay) {
		if (!all_double) {
			new_farms.clear();
			num_farms.push_back(num_farms[i]);
			all_double = true;
			FOR(j, farms.size()) {
				farms[j] *= 2;
				if (farms[j] > C) {
					new_farm_cows = farms[j] / 2;
					farms[j] -= new_farm_cows;
					num_farms[i + 1]++;
					new_farms.push_back(new_farm_cows);
				}
				else
					all_double = false;


			}
			for (int n : new_farms) {
				farms.push_back(n);
			}
		}
		else
			num_farms.push_back(2 * num_farms[i]);
			
	}

	for (int i : days)
		cout << num_farms[i] << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cow();
    return 0;
}