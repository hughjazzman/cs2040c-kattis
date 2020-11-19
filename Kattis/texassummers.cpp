#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <climits>
#include <stack>

using namespace std;

typedef pair<int, int> ii;

int sqdist(ii &p1, ii &p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

void dijkstra(vector<ii> & g) {
	vector<bool> b(g.size(), false);
    vector<int> d(g.size(), INT_MAX);
    vector<int> pth(g.size(), -1);
	set<ii> q;
    int s = g.size() - 2;
	q.insert({0, s});
    b[s] = true;
    d[s] = 0;

	while (!q.empty()) {
        int v = q.begin()->second;
        ii vpos = g[v];
		q.erase(q.begin());
		for (int i = 0; i < g.size(); ++i) {
            int cd = d[i], clen = sqdist(vpos, g[i]);
			if (cd > d[v] + clen) {
				q.erase({cd, i});
				d[i] = d[v] + clen;
				q.insert({d[i], i});
                pth[i] = v;
			}

		}
	}
    if (pth.back() == -1 || pth.back() == s) {
        cout << '-';
        return;
    }
    int n = s + 1;
    stack<int> stk;
    while (pth[n] != s) {
        stk.push(pth[n]);
        n = pth[n];
    }
    while (!stk.empty()) {
        cout << stk.top() << '\n';
        stk.pop();
    }
}

void texs() {
    int n, x, y;
    cin >> n;
    vector<ii> g(n+2);
    for (int i = 0; i < n + 2; ++i) {
        cin >> x >> y;
        g[i]= {x,y};
    }

    dijkstra(g);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    texs();
    return 0;
}