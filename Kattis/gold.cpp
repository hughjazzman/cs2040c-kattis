#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

#define FOR(i,k) for(int i=0;i<k;i++)

void bfs(vector<string> & v, int px, int py) {
	int dir[][2] = { {-1,0},{1,0},{0,1}, {0,-1} }, cnt = 0;
	queue<ii> q;
	vector<vector<bool>> b(v.size(), vector<bool>(v[0].size(), false));
	q.push({ px, py });

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		bool safe = true;

		FOR(i, 4) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx < 0 || nx >= v.size() || ny < 0 || ny >= v[0].size()) continue;
			if (v[nx][ny] == 'T') {
				safe = false;
				break;
			}
		}

		if (!safe) continue;

		FOR(i, 4) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx < 0 || nx >= v.size() || ny < 0 || ny >= v[0].size()) continue;
			if (v[nx][ny] == '#' || b[nx][ny]) continue;
			if (v[nx][ny] == 'G')
				cnt++;
			b[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	cout << cnt;
}

void gold() {
	int W, H, px=0, py=0;
	
	char c;
	cin >> W >> H;
	vector<string> v(H);
	FOR(i, H) {
		FOR(j, W) {
			cin >> c;
			if (c == 'P') {
				px = i;
				py = j;
			}
			v[i].push_back(c);
		}
	}

	bfs(v, px, py);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    gold();
    return 0;
} 