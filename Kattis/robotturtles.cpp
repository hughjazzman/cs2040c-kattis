#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <tuple>
#include <set>

#define FOR(i,k) for(int i=0;i<k;i++)

#define SIZE 8
#define MAX 1000


using namespace std;

typedef tuple<int, int, int, char> iiic;
typedef pair<int, string> is;

struct comp {
	bool operator() (const iiic &lhs, const iiic& rhs) const
	{
		return get<0>(lhs) > get<0>(rhs);
	}
};

char turn(int i, char face, string &moves) {
	// Function to turn turtle
	// will never make 180
	switch (i) {
	case 0: // right
		if (face == 'U') moves.append("R");
		if (face == 'D') moves.append("L");
		return 'R';
	case 1: // left
		if (face == 'U') moves.append("L");
		if (face == 'D') moves.append("R");
		return 'L';
	case 2: //down
		if (face == 'R') moves.append("R");
		if (face == 'L') moves.append("L");
		return 'D';
	case 3: // up
		if (face == 'R') moves.append("L");
		if (face == 'L') moves.append("R");
		return 'U';
	
	}
}

void robot() {
	// actual grid
	char grid[SIZE][SIZE];
	// distance path grid
	vector<vector<is>> distPath(SIZE, vector<is>(SIZE, make_pair(MAX, "")));
	// distance, index queue
	priority_queue<iiic, vector<iiic>, comp> v;

	int dia_i, dia_j;
	FOR(i, SIZE) {
		FOR(j, SIZE) {
			cin >> grid[i][j];
			if (grid[i][j] == 'D') {
				dia_i = i;
				dia_j = j;
			}
			if (i == SIZE - 1 && j == 0) {
				distPath[i][j] = make_pair(0, "");
				v.push(make_tuple(0, i, j, 'R'));
				continue;
			}
			distPath[i][j] = make_pair(MAX, "");
		}
	}

	string moveGrid[SIZE][SIZE];

	// right, left, 
	int dir[][2] = { {0,1},{0,-1},{1,0},{-1,0} };

	
	// path length, row index, col index, direction, path

	while (!v.empty()) {
		iiic curr = v.top();
		
		int r = get<1>(curr), c = get<2>(curr), dist = get<0>(curr);
		char face = get<3>(curr);
		v.pop();
		FOR(i, 4) {
			string moves = distPath[r][c].second;
			int n_dist = dist;
			int n_r = r + dir[i][0], n_c = c + dir[i][1];
			if (n_r < 0 || n_r >= SIZE || n_c < 0 || n_c >= SIZE) continue;
			char cc = grid[n_r][n_c];
			if (cc == 'C' || cc == 'T') continue;
			char n_face;
			n_face = turn(i, face, moves);
			if (n_face != face) n_dist++;
			
			if (cc == 'I') {
				moves.append("X");
				n_dist++;
			}
			moves.append("F"); n_dist++;
			
			if (n_dist >= distPath[n_r][n_c].first) continue;
			distPath[n_r][n_c] = make_pair(n_dist, moves);
			v.push(make_tuple(n_dist, n_r, n_c, n_face));
		}

	}
	if (distPath[dia_i][dia_j].first != MAX)
		cout << distPath[dia_i][dia_j].second;
	else
		cout << "no solution";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    robot();
    return 0;
}