#include <vector>
#include <iostream>
#include <climits>
#include <set>

using namespace std;

typedef pair<int, int> ii;

void dijkstra(vector<vector<ii>> & g, int s, vector<int> &dist) {
	dist[s] = 0;
	set<ii> q;
	q.insert(make_pair(0, s));

	while (!q.empty()) {
		int v = q.begin()->second, pd = dist[v];
		q.erase(q.begin());
		for (ii x : g[v]) {
			int i = x.second;
			int cd = dist[i], clen = x.first;
			if (cd > dist[v] + clen) {
				q.erase(make_pair(cd, i));
				dist[i] = dist[v] + clen;
				q.insert(make_pair(dist[i], i));
			}

		}
	}
}

void sp1() {
	int n, m, q, s, u, v, w, qr;

	while (cin >> n >> m >> q >> s) {
		if (!(n || m || q || s)) return;
		vector<vector<ii>> g(n);
		vector<int> d(n, INT_MAX);

		while (m--) {
			cin >> u >> v >> w;
			g[u].push_back({ w,v });
		}

		dijkstra(g, s, d);

		while (q--) {
			cin >> qr;
			if (d[qr] < INT_MAX)
				cout << d[qr];
			else
				cout << "Impossible";
			cout << '\n';
		}
		cout << '\n';
	}
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sp1();
    return 0;
} 