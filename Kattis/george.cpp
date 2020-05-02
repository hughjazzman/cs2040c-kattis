// CS2040/C Past Finals F

#include <vector>
#include <iostream>
#include <climits>
#include <set>

#define FOR(i,k) for(int i=0;i<k;i++)

using namespace std;

typedef pair<int, int> ii;

// For debugging
void print(vector<vector<ii>> & g) {
	for (auto i : g) {
		for (auto j : i)
			cout << j.first << ',' << j.second << ' ';
		cout << endl;
	}
	cout << endl;
}

int dijkstra(vector<vector<ii>> & g, int s, int d, int st) {
	vector<int> dist(g.size(), INT_MAX);
	dist[s] = st;
	set<ii> q;
	q.insert(make_pair(st, s));

	while (!q.empty()) {
		int v = q.begin()->second, pd = dist[v];
		if (v == d) return pd;
		q.erase(q.begin());
		FOR(i, g.size()) {
			if (g[v][i].first == -1) continue;
			int cd = dist[i], clen = g[v][i].first, ga = g[v][i].second;
			// If Mister George on the street add wait time
			if (pd >= ga && pd < ga + clen)
				clen += ga + clen - pd;
			if (cd > dist[v] + clen) {
				q.erase(make_pair(cd, i));
				dist[i] = dist[v] + clen;
				q.insert(make_pair(dist[i], i));
			}

		}
	}
}

void george() {
	int N, M, A, B, K, G, r, x, y, t;
	cin >> N >> M >> A >> B >> K >> G;
	vector<vector<ii>> g(N, vector<ii>(N, make_pair(-1, -1))); // AM
	vector<int> p;
	// Store George route first
	while (G--) {
		cin >> r;
		p.push_back(--r);
	}

	while (M--) {
		cin >> x >> y >> t;
		g[--x][--y].first = t;
		g[y][x].first = t;
	}
	
	// Insert Mister George start time at each intersection of route
	int time = 0;
	FOR(i, p.size() - 1) {
		int a = p[i], b = p[i + 1];
		g[a][b].second = time;
		g[b][a].second = time;
		time += g[a][b].first;
	}
	int res = dijkstra(g, --A, --B, K);
	cout << res - K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    george();
    return 0;
}