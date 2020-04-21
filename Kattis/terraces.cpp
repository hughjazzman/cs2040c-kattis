#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <tuple>

#define FOR(i,k) for(int i=0;i<k;i++)


using namespace std;

typedef pair<int, int> ii;

void terraces() {
	int x, y;
	cin >> y >> x;
	vector <vector<int>>grid(x, vector<int>(y));
	vector <vector<bool>>visited(x, vector<bool>(y,false));
	FOR(i, x) {
		FOR(j, y) {
			cin >> grid[i][j];
		}
	}
	queue <ii> q;
	int dir[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	int total = 0;
	FOR(i, x) {
		FOR(j, y) {
			if (visited[i][j]) continue;
			q.push(make_pair(i, j));
			visited[i][j] = true;
			int count = 0;
			bool small = true;
			while (!q.empty()) {
				count++;
				int curr_i = q.front().first, curr_j = q.front().second;
				int curr_height = grid[curr_i][curr_j];
				q.pop();
				
				
				FOR(k, 4) {
					int i_n = curr_i + dir[k][0], j_n = curr_j + dir[k][1];
					
					if (i_n < 0 || i_n >= x || j_n < 0 || j_n >= y) continue;
					int h_n = grid[i_n][j_n];
					if (h_n > curr_height) continue;
					if (!visited[i_n][j_n] && h_n == curr_height) {
						q.push(make_pair(i_n, j_n));
						visited[i_n][j_n] = true;
					}
					if (h_n < curr_height)
						small = false;
				}
			}
			if (small) total += count;
		}
	}
	cout << total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    terraces();
    return 0;
}