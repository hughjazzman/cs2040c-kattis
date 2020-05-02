// CS2040/C Past Finals L

#include <vector>
#include <iostream>
#include <climits>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long ll;
typedef pair<ll, ll> lili;

void dijkstra(vector<vector<ii>> & g, vector<ll> & dist) {
	set<lili> st;
	// source vertex is 1 (go backwards)
	dist[1] = 0;
	st.insert(make_pair(0, 1));
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		// going thru distance stored from one node to another
		for (auto e : g[v]) {
			int nv = e.second;
			ll cd = dist[nv], clen = e.first;
			
			if (cd > dist[v] + clen) {
				st.erase(make_pair(cd, nv));
				dist[nv] = dist[v] + clen;
				st.insert(make_pair(dist[nv], nv));
			}
		}
	}
}

void bfs(vector<vector<int>>& g, vector<int> &p) {
	queue<int> q;
	vector<bool> v(g.size(), false);
	v[0] = true;
	q.push(0);

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int to : g[n]) {
			if ( v[to]) continue;
			v[to] = true;
			p[to] = n;
			q.push(to);
		}
	}
}

void detour() {
	int n, m, a, b, d;
	cin >> n >> m;
	// Graph as AL
	vector<vector<ii>> g(n);
	// Graph as EL
	vector<iii> edges;
	// Distance value array for each vertex
	vector<ll> dist(n, LLONG_MAX);
	// Previous vertex array
	vector<int> prev(n, -1);
	
	// Process edges
	while (m--) {
		cin >> a >> b >> d;
		g[a].push_back(make_pair(d, b));
		g[b].push_back(make_pair(d, a));
		edges.push_back(make_tuple(a, b, d));
	}
	
	// Dijkstra to get SP
	dijkstra(g, dist);
	
	// AL graph for BFS for final route
	vector<vector<int>> g2(n);
	// Add correct edges to graph
	for (auto e : edges) {
		a = get<0>(e);
		b = get<1>(e);
		d = get<2>(e);
		// Distance here is from vertex 1
		// If edge is part of ideal route
		// do not add it (add the opposite)
		if (dist[a] + d == dist[b])
			g2[a].push_back(b);
		else if (dist[b] + d == dist[a])
			g2[b].push_back(a);
		else {
			g2[a].push_back(b);
			g2[b].push_back(a);
		}
	}

	int i = 1;
	// BFS to get a valid route
	bfs(g2, prev);
	
	// If BFS failed to reach vertex 1
	if (prev[i] == -1)
		cout << "impossible";
	else {
		vector<int> v;
		int cnt = 1;
		
		// Add entire path
		v.push_back(i);
		while (i) {
			v.push_back(prev[i]);
			i = prev[i];
			cnt++;
		}
		// Reverse path
		reverse(v.begin(), v.end());
		
		// Result
		cout << cnt << ' ';
		for (int j : v)
			cout << j << ' ';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    detour();
    return 0;
}