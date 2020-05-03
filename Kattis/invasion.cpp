#include <vector>
#include <iostream>
#include <climits>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

void print(vector<int> & dist) {
	for (int i : dist)
		cout << i << ' ';
	cout << endl;
}


void dijkstra(vector<vector<ii>> & g, int s, vector<int> & dist, vector<bool> & vis, int *cnt, int K) {
	dist[s] = 0;
	set<ii> q;
	q.insert(make_pair(0, s));
	// Source becomes unsafe if it wasn't already
	if (!vis[s]) {
		vis[s] = true;
		(*cnt)--;
	}
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (auto e : g[v]) {
			int nv = e.second, cd = dist[nv], clen = e.first;
			if (cd > dist[v] + clen) {
				q.erase(make_pair(cd, nv));
				dist[nv] = dist[v] + clen;
				q.insert(make_pair(dist[nv], nv));
				// Reduce safe count if new town falls under threshold
				// vis will only turn true here or as a source
				if (dist[nv] < K && !vis[nv]) {
					(*cnt)--;
					vis[nv] = true;
				}
			}
		}
	}
	cout << *cnt << '\n';
}

void inv() {
	int N, M, A, K, T1, T2, D, B, cnt;
	cin >> N >> M >> A >> K;
	while (N || M || A || K) {
		vector<vector<ii>> g(N); // AL
		vector<int> dist(N, INT_MAX);
		vector<bool> vis(N, false);
		cnt = N;
		while (M--) {
			cin >> T1 >> T2 >> D;
			g[--T1].push_back(make_pair(D, --T2));
			g[T2].push_back(make_pair(D, T1));
		}
		while (A--) {
			cin >> B;
			dijkstra(g, --B, dist, vis, &cnt, K);
		}
		cout << '\n';
		cin >> N >> M >> A >> K;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inv();
    return 0;
}