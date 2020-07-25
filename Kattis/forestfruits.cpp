#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <climits>		// LLONG_MAX
#include <algorithm>	// greater
#include <queue>		// priority_queue
#include <unordered_set>

using namespace std;

#define FOR(i,k) for(ll i=0;i<k;i++)

typedef long long ll;
typedef pair<ll, ll> llll;


void dijkstra(vector<vector<llll>>& g, vector<ll>& dist, unordered_set<int> &bush, priority_queue<llll, vector<llll>, greater<llll>> &md) {
	ll n, d, nn, len;
	
	dist[0] = 0;
	set<llll> q;
	q.insert({ 0, 0 });

	while (!q.empty()) {
		n = q.begin()->second;
		q.erase(q.begin());

		if (bush.count(n))
			md.push({ dist[n], n });

		for (auto e : g[n]) {
			nn = e.first, d = dist[nn], len = e.second;
			if (d <= dist[n] + len) continue;
			
			dist[nn] = dist[n] + len;
			q.erase({ d, nn });
			q.insert({ dist[nn], nn });
		}

	}
}



void fruits() {
	ll V, E, C, K, M, u, v, w, f;
	unordered_set<int> bush; // clearings

	cin >> V >> E >> C >> K >> M;

	vector<vector<llll>> g(V); // graph

	while (E--) {
		cin >> u >> v >> w;
		--u; --v;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	while (C--) {
		cin >> f;
		--f;
		bush.insert(f);
	}

	// priority queue for min distance
	priority_queue<llll, vector<llll>, greater<llll>> md;
	// final max distances
	ll xd = -1;
	// distance of each clearing
	vector<ll> dist(V, LLONG_MAX);
	// regrown clearings on each day
	map<ll, ll> days;

	dijkstra(g, dist, bush, md);

	int check = min(K, M);

	FOR(i, check) {
		if (days.count(i))
			md.push({ dist[days[i]], days[i] });
		
		if (md.empty()) {
			cout << -1;
			return;
		}
		ll cd = md.top().first;
		if (cd > xd) xd = cd;


		int n = md.top().second;
		if (i + K < M)
			days[i + K] = n;

		md.pop();
	}

	cout << 2 * xd;
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fruits();
    return 0;
}