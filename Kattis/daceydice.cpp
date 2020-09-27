#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef tuple<int, int, int> iii;

#define FOR(i,k) for(int i=0;i<k;i++)

struct key_hash : public std::unary_function<iii, std::size_t>
{
	std::size_t operator()(const iii& k) const
	{
		return std::get<0>(k) ^ std::get<1>(k) ^ std::get<2>(k);
	}
};

iii turn(iii dice, int dir) {
	int top = get<0>(dice), right = get<1>(dice), back = get<2>(dice);
	switch (dir) {
	case 0: // forward
		return { back, right, 7 - top };
	case 1: // right
		return { 7 - right, top, back };
	case 2: // back
		return { 7 - back, right, top };
	case 3: // left
		return { right, 7 - top, back };
    default:
        return {1,2,3};
	}
}

iii rotateDice(iii dice, int dir) {
	int top = get<0>(dice), right = get<1>(dice), back = get<2>(dice);
	if (dir) // longitudinal left
		return turn(dice, 3);
	else // normal right
		return { top, 7 - back, right };
}


void findOrientations(vector<iii> & arr, unordered_map<iii, int, key_hash>& mp) {
	int moves[] = { 1, 0, 0, 0 };
	iii dice = {1, 2, 3};
	int k = 0;
	FOR(i, 3) {
		FOR(j, 4) {
			dice = rotateDice(dice, moves[j]);
			mp[dice] = k;
			// add orientation
			arr[k++] = dice;

			// add its "opposite"
			int top = get<0>(dice), right = get<1>(dice), back = get<2>(dice);
			iii op_dice = { 7 - top, right, 7 - back };
			mp[op_dice] = k;
			arr[k++] = op_dice;
		}
	}
}

void bfs(vector<string>& g, int x, int y, unordered_map<iii, int, key_hash>& mp, vector<iii> &arr) {
	int dir[][2] = { {-1,0},{0, 1},{1,0},{0,-1} };
	queue<iii> q;
	vector<vector<vector<bool>>> vis(g.size(), vector<vector<bool>>(g.size(), vector<bool>(24, false)));
	q.push({ x,y,22 });

	while (!q.empty()) {
		int r = get<0>(q.front()), c = get<1>(q.front()), o_i = get<2>(q.front());
		iii o = arr[o_i];
		q.pop();

		FOR(i, 4) {
			iii no = turn(o, i);
			int nr = r + dir[i][0], nc = c + dir[i][1], no_i = mp[no];

			// out of bounds
			if (nr < 0 || nr >= g.size() || nc < 0 || nc >= g.size()) continue;
			// visited with same orientation
			if (vis[nr][nc][no_i]) continue;
			// magnet
			if (g[nr][nc] == '*') continue;

			if (g[nr][nc] == 'H' && get<0>(no) == 2) {
				cout << "Yes" << '\n';
				return;
			}

			vis[nr][nc][no_i] = true;
			q.push({ nr, nc, no_i });

		}

	}
	cout << "No" << '\n';
}



void dd() {
	vector<iii> arr(24);
	unordered_map<iii, int, key_hash> mp;
	findOrientations(arr, mp);
	
	int t, n, x =0 , y = 0;
	char c;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> g(n);
		FOR(i, n) {
			FOR(j, n) {
				cin >> c;
				g[i].push_back(c);
				if (c == 'S') {
					x = i;
					y = j;
				}
			}
		}

		bfs(g, x, y, mp, arr);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dd();
    return 0;
}