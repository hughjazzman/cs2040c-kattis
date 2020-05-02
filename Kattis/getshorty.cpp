// CS2040/C Past Finals D

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <tuple>
#include <set>
#include <math.h>
#include <iomanip>
#include <cfloat>

#define FOR(i,k) for(int i=0;i<k;i++)


using namespace std;

typedef pair<int, int> ii;
typedef pair<int, float> id;

void addEdge(vector < vector<id>> & g, int x, int y, float f) {
	f = -log(f);
	g[x].push_back(make_pair(y, f));
	g[y].push_back(make_pair(x, f));
}

float dijkstra(vector < vector<id>>& g, int s, int d) {
	vector<float> dist(g.size(), FLT_MAX);
	dist[s] = 0;
	set<ii> st; // stores distance, vertex pairs
	st.insert(make_pair(0, s));

	while (!st.empty()) {
		int v = st.begin()->second;
		if (v == d) return dist[v];
		st.erase(st.begin());
		for (auto to : g[v]) {
			int nv = to.first;
			float cd = dist[nv], clen = to.second;
			if ( cd > dist[v] + clen) {
				st.erase(make_pair(cd, nv));
				dist[nv] = dist[v] + clen;
				st.insert(make_pair(dist[nv], nv));
			}
		}
	}

}


void shorty() {
	int n, m, x, y;
	float f , d;
	cin >> n >> m;
	
	while (n || m) {
		vector<vector<id>> g(n);
		while (m--) {
			cin >> x >> y >> f;
			addEdge(g, x, y, f);
		}
		d = dijkstra(g, 0, n - 1);
		cout << fixed << setprecision(4) << exp(-d) << endl;
		cin >> n >> m;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    shorty();
    return 0;
}