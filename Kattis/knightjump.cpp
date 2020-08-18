#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

#define FOR(i,k) for(int i=0;i<k;i++)

void bfsk(vector<string>& g, int x, int y) {
	if (!(x || y)) {
		cout << 0;
		return;
	}
	vector<ii> dir;
	FOR(i, 2) {
		FOR(j, 2) {
			if (i == j) continue;
			dir.push_back({ i + 1, j + 1});
			dir.push_back({ -(i + 1), j + 1 });
			dir.push_back({ i + 1, -(j + 1) });
			dir.push_back({ -(i + 1),-(j + 1) });
		}
	}
	vector<vector<bool>> b(g.size(), vector<bool>(g.size(), false));
	queue<iii> q;
	q.push({ {x,y},0 });

	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second;
		int d = q.front().second;
		q.pop();


		FOR(i, 8) {
			int nx = x + dir[i].first, ny = y + dir[i].second;
			if (nx < 0 || nx >= g.size() || ny < 0 || ny >= g.size()) continue;
			if (g[nx][ny] == '#' || b[nx][ny]) continue;
			if (!(nx || ny)) {
				cout << d + 1;
				return;
			}
			b[nx][ny] = true;
			q.push({ {nx, ny}, d + 1 });
		}
	}
	cout << -1;
}

void kj() {
	int n, x = 0, y = 0;
	char c;
	cin >> n;
	vector<string> g(n);
	
	FOR(i, n) {
		FOR(j, n) {
			cin >> c;
			g[i].push_back(c);
			if (c == 'K') {
				x = i;
				y = j;
			}
		}
	}

	bfsk(g, x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    kj();
    return 0;
}