// CS2040/C Past Finals J

#include <vector>
#include <iostream>
#include <climits>
#include <set>
#include <tuple>
#include <utility>

#define FOR(i,k) for(int i=0;i<k;i++)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

void dijkstra(vector<vector<int>> & g, int h, int w) {
	// Distance array
	vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
	// Previous array
	vector<vector<ii>> prev(h, vector<ii>(w));
	// Last node distance & previous
	int total = INT_MAX;
	ii last_pre;
	
	// 8 directions initialization
	int a[] = { -1, 0, 1 };
	int dir[8][2];
	int k = 0;
	FOR(i, 3) {
		FOR(j, 3) {
			if (i == 1 && j == 1) continue;
			dir[k][0] = a[i];
			dir[k][1] = a[j];
			k++;
		}
	}
	
	// Create pq
	set<iii> q;
	// Insert all of the top squares
	FOR(i, w) {
		dist[0][i] = g[0][i];
		q.insert(make_tuple(g[0][i], 0, i));
	}
	
	while (!q.empty()) {
		int vr = get<1>(*q.begin()), vc = get<2>(*q.begin());
		q.erase(q.begin());
		FOR(i, 8) {
			int nvr = vr + dir[i][0], nvc = vc + dir[i][1], cd = total, clen = 0;
			if (nvr < 0 || nvc < 0 || nvc >= w) continue;
			if (nvr != h) {
				cd = dist[nvr][nvc];
				clen = g[nvr][nvc];
			}
			if (cd > dist[vr][vc] + clen) {
				if (nvr == h) {
					total = dist[vr][vc];
					last_pre = make_pair(vr, vc);
				}
				else {
					q.erase(make_tuple(cd, nvr, nvc));
					dist[nvr][nvc] = dist[vr][vc] + clen;
					q.insert(make_tuple(dist[nvr][nvc], nvr, nvc));
					prev[nvr][nvc] = make_pair(vr, vc);
				}
				
			}
		}
	}
	
	// 0 out path taken in SP
	int cr = last_pre.first, cc = last_pre.second, tr = cr;
	while (cr) {
		g[cr][cc] = 0;
		cr = prev[cr][cc].first;
		cc = prev[tr][cc].second;
		tr = cr;
	}
	g[0][cc] = 0;

}

void print(vector<vector<int>>& g) {
	for (auto v : g) {
		for (int i : v) {
			if (!i)
				cout << ' ';
			else
				cout << i;
		}
		cout << endl;
	}
	cout<< endl;
}

void block() {
	int h, w;
	char c;
	cin >> h >> w;
	
	while (h || w) {
		vector<vector<int>> g(h, vector<int>(w));
		FOR(i, h) {
			FOR(j, w) {
				cin >> c;
				g[i][j] = c - '0';
			}
		}
		dijkstra(g, h, w);
		print(g);
		cin >> h >> w;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    block();
    return 0;
}