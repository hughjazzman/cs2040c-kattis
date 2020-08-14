#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

void trav() {
	int k, n, m, u, v, d, z, a, b, c;
	
	cin >> k >> n >> m;
	vector<vector<ii>> g(k * n);
	// initial num customers at each airport each day
	// day i, airport j corresponds to (i-1)*k+(j-1)
	// day n + 1 slots added for convenience
	vector<int> ncust(k * (n+1), 0); 
	while (m--) {
		cin >> u >> v >> d >> z;
		--u; --v; // 0-based
		g[(d - 1) * k + u].push_back({ d * k + v,z });
	}
	for (int i = 0; i < k * n; i++) {
		cin >> a >> b >> c;
		--a; --b;
		ncust[b * k + a] = c;
	}

	for (int i = 0; i < g.size(); i++) {
		for (ii e : g[i]) {
			if (e.second > ncust[i]) {
				cout << "suboptimal";
				return;
			}
			ncust[i] -= e.second;
			ncust[e.first] += e.second;
		}
		if (i + k >= k * n) continue;
		ncust[i + k] += ncust[i];
		ncust[i] = 0;
	}
	cout << "optimal";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    trav();
    return 0;
}