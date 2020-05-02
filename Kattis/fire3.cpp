// CS2040/C Past Finals A
#include <vector>
#include <queue>
#include <iostream>
#include <utility>

using namespace std;
using twindex = pair<int, int>;
using twinch = pair<char, int>;

int bfs(queue<twindex> &q, vector<vector<twinch>> &grid, int R, int C) {

	int curr_i, curr_j;
	char curr_k;
	int dir[][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	int i_n, j_n, currdst;

	twindex currpt;

	while (!q.empty()) {
		currpt = q.front();
		// Get index of curr pt
		curr_i = currpt.first;
		curr_j = currpt.second;
		// Get char of curr pt
		curr_k = grid[curr_i][curr_j].first;
		// Used to get time taken to travel for J
		currdst = grid[curr_i][curr_j].second;
		q.pop();		

		// For all 4 directions
		for (int z = 0; z < 4; z++) {
			i_n = curr_i + dir[z][0];
			j_n = curr_j + dir[z][1];
			// If out of bounds
			if (i_n < 0 || i_n >= R || j_n < 0 || j_n >= C) {
				// Continue if Fire
				if (curr_k == 'F') continue;
				// Return time if J
				else return currdst + 1;
			}
			char c = grid[i_n][j_n].first;
			// If wall skip, if F already its place in queue so skip
			if (c == '#' || c == 'F') continue;
			// Make sure only update when passable for J
			if (c == 'J' && curr_k == 'J') continue;
			// Change square to either J / F, keeping currdst for J (don't care for F)
			grid[i_n][j_n] = make_pair(curr_k, currdst+1);
			// Add new direction to queue
			q.push(make_pair(i_n, j_n));
		}
	}
	return -1; // Impossible
}

void fire() {
	int R, C, dist;
	char k ;
	
	cin >> R >> C;
	// To store grid, stores char and distance
	vector <vector<twinch>> grid(R, vector<twinch> (C));
	// For BFS on J and F, stores indexes
	queue <twindex> q,qF;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> k;
			grid[i][j] = make_pair(k, 0);
			// Put them in the queue
			// Need J to be first so that not overwritten by F
			if (k == 'J')
				q.push(make_pair(i, j));
			else if (k == 'F')
				qF.push(make_pair(i, j));
		}
	}
	// To ensure J is first for BFS
	while (!qF.empty()) {
		q.push(qF.front());
		qF.pop();
	}

	// Returns -1 if impossible
	dist = bfs(q, grid, R, C);
	if (dist >= 0)
		cout << dist;
	else
		cout << "IMPOSSIBLE";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fire();
    return 0;
}