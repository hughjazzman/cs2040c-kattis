#include <vector>
#include <iostream>
#include <climits>
#include <set>
#include <algorithm>

#define FOR(i,k) for(int i=0;i<k;i++)

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

void dijkstra(vector<vector<ii>>& g, int s, int t, int k) {
	bool found = false;
	vector<vector<int>> dist(g.size(), vector<int>(30, INT_MAX));
	dist[s] = vector<int>(30, 0);
	set<iii> q;
	q.insert({ {0,s},0 });

	while (!q.empty()) {
		int v = q.begin()->first.second, dep = q.begin()->second;
		int cnd = q.begin()->first.first;
		//cout << v << ' ' << dep << endl;
		if (v == t)
			found = true;
		q.erase(q.begin());
		if (dep >= k - 1 ) continue;
		for (ii x : g[v]) {
			int i = x.second;
			int cd = dist[i][dep+1], clen = x.first;
			if (cd > cnd + clen) {
				dist[i][dep+1] = cnd + clen;
				//cout << dist[i] << ' ' << i << ' ' << dep + 1 << endl;
				q.insert({ {dist[i][dep+1],i},dep + 1 });
			}

		}
	}
	if (found)
		cout << *min_element(dist[t].begin(), dist[t].end());
	else
		cout << -1;
	cout << '\n';
}

void sp4() {
	int TC, V, X, vx, w, Q, s, t, k;
	cin >> TC;

	while (TC--) {
		cin >> V;
		vector<vector<ii>> g(V);
		FOR(i, V) {
			cin >> X;
			while (X--) {
				cin >> vx >> w;
				g[i].push_back({ w,vx });
			}
		}


		cin >> Q;
		while (Q--) {
			cin >> s >> t >> k;
			dijkstra(g, s, t, k);
		}
		cout << '\n';
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sp4();
    return 0;
} 