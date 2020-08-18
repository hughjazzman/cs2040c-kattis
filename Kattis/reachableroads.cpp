#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i,k) for(int i=0;i<k;i++)

int bfs(vector<vector<int>> &g) {
	vector<bool> b(g.size(), false);
	queue<int> q;
	int c = -1;

	FOR(i, g.size()) {
		if (b[i]) continue;
		q.push(i);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : g[u]) {
				if (!b[v])
					q.push(v);
				b[v] = true;
			}
		}
		c++;
	}
	return c;
}

void rr() {
	int n, m, r, u, v;
	cin >> n;
	while (n--) {
		cin >> m >> r;
		vector<vector<int>> g(m);
		while (r--) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		cout << bfs(g) << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    rr();
    return 0;
}