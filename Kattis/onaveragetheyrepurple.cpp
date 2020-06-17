#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int bfs(vector<vector<int>> &g, int n) {
	queue<ii> q;
	vector<bool> vis(n, false);
	int v, d;
	q.push(make_pair(0,0));

	while (!q.empty()) {
		v = q.front().first;
		d = q.front().second;
		q.pop();

		for (int v2 : g[v]) {
			if (v2 == n) return d;
			if (vis[v2]) continue;
			vis[v2] = true;
			q.push(make_pair(v2, d+1));
		}
	}
	return 0;
}



void purple() {
	int n, m, a, b;
	
	cin >> n >> m;
	vector<vector<int>> g(n);
	while (m--) {
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cout << bfs(g, n-1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    purple();
    return 0;
}