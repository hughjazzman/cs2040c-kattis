#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define FOR(i,k) for(int i=0;i<k;i++)

bool safe(vector<vector<int>> & g, int i, vector<bool> & vis, vector<bool> & rec, vector<bool> & b) {
	vis[i] = true;
	rec[i] = true;
	bool cyc = false;
	for (int w : g[i]) {
		if (!vis[w]) {
			cyc |= safe(g, w, vis, rec, b);

		}
		else if (rec[w] || b[w]) {
			cyc = true;
		}
			
	}
	rec[i] = false;
	b[i] = cyc;
	return cyc;
}

void dfs(vector<vector<int>> & g, vector<bool> & b, int ncit) {
	vector<bool> vis(g.size(), false), rec(g.size(), false);

	FOR(i, ncit) {		
		if (vis[i]) continue;
		safe(g, i, vis, rec, b);
	}
}


void rm() {
	int n, i = 0, o_i = 0, d_i = 0, ncit = 0;
	string o, d;
	unordered_map<string, int> mp;
	

	cin >> n;
	vector<vector<int>> g(10001);
	vector<bool> b(10001, false);

	while (n--) {
		cin >> o >> d;
		if (!mp.count(o)) {
			mp[o] = i;
			o_i = i++;
			ncit++;
		}
		else
			o_i = mp[o];
		if (!mp.count(d)) {
			mp[d] = i;
			d_i = i++;
			ncit++;
		}
		else
			d_i = mp[d];
		g[o_i].push_back(d_i);
	}
	dfs(g, b, ncit);
	while (cin >> o) {
		cout << o << ' ';
		if (b[mp[o]])
			cout << "safe";
		else
			cout << "trapped";
		cout << '\n';
	}
		
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    rm();
    return 0;
}