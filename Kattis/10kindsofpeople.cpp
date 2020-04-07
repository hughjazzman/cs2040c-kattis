#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <tuple>
#include <stack>


using namespace std;

#define FOR(i,k) for(int i=0;i<k;i++)


void bfs(int num, stack<pair<int,int>> &q, vector<vector<int>> &b) {
	int numR = b.size(), numC = b[0].size();

	// directions 
	int dir[][2] = { {1,0},{-1,0},{0,1},{0,-1} };

	while (!q.empty()) {
		int r = q.top().first, c = q.top().second;

		q.pop();
		b[r][c] = num;
		FOR(i, 4) {
			int n_r = r + dir[i][0], n_c = c + dir[i][1];
			
			if (n_r < 0 || n_r >= numR || n_c < 0 || n_c >= numC) continue;
			int n_num = b[n_r][n_c];
			if (n_num == num || n_num >= 2 || (num % 2) ^ n_num) continue; // if not passable

			q.push(make_pair(n_r, n_c));

		}
	}
	
}

void ten() {
	int r, c;
	cin >> r >> c;

	vector<vector<int>> b(r,vector<int>(c));
	
	char ch;

	FOR(i,r) {
		FOR(j, c) {
			cin >> ch;
			b[i][j] = ch - '0';
		}
	}
	int num = 1;
	stack<pair<int, int>> st;

	int n,r1,c1,r2,c2;
	
	cin >> n;

	FOR(i, n) {
		cin >> r1 >> c1 >> r2 >> c2;
		--r1; --c1; --r2; --c2;

		int num1 = b[r1][c1], num2 = b[r2][c2];

		if (num1 < 2) {
			num += ((num % 2) ^ num1) ? 1 : 2;
			st.push(make_pair(r1, c1));
			bfs(num,st, b);
		}

		if (b[r2][c2] == b[r1][c1]) {
			if (b[r1][c1] % 2)
				cout << "decimal";
			else
				cout << "binary";
		}
		else
			cout << "neither";
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ten();
    return 0;
}