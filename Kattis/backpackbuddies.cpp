#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> ii;

void dijkstra(vector<vector<ii>> & g, vector<int> & dist, int n) {
	dist[0] = 0;
	set<ii> q;
	q.insert({ 0, 0 });

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		if (v == dist.size() - 1) return;

		for (ii e : g[v]) {
			int nv = e.second, d = dist[nv], len = e.first, nlen = len;
			
			
			// if mr day
			if (n) {
				for (int i = 1; i < nlen; i++) {
					// if cross into nightime, add mr day waiting time
					if ((dist[v]+i) % 12 == 0) {
						len += i;
						break;
					}
				}
			}

			if (d <= dist[v] + len) continue;

			dist[nv] = dist[v] + len;
			q.erase({ d, nv });
			q.insert({ dist[nv], nv });
		}

	}
}

void bkbd() {
	int n, m, u, v, d;
	cin >> n >> m;
	vector<vector<ii>> g(n);
	vector<int> dist0(n, INT_MAX), dist1(n, INT_MAX);
	while (m--) {
		cin >> u >> v >> d;
		g[u].push_back({ d, v });
		g[v].push_back({ d, u });
	}

	dijkstra(g, dist0, 0);
	dijkstra(g, dist1, 1);

	int dt0 = dist0[n - 1], dt1 = dist1[n - 1], res = 0;

	while (dt0 != dt1) {
		res++;
		dt0++;
		if (dt0 % 12 == 1) // new day
			res += 12;
	}

	cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bkbd();
    return 0;
}