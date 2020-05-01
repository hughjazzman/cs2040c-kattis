#include <vector>
#include <iostream>
#include <queue>
#include <utility> // pair

#define FOR(i,k) for(int i=0;i<k;i++)

using namespace std;

typedef pair<int, int> ii;

// To debug
void print(vector<int> & g) {
	for (int i : g)
		cout << i << ' ';
	cout << endl;
}

// Union 
void un(int K, int L, vector<int> &eq, vector<int> &size) {
	if (eq[K] == -1) eq[K] = K;
	if (eq[L] == -1) eq[L] = L;
	while (eq[K] != K) K = eq[K];
	while (eq[L] != L) L = eq[L];
	if (size[K] > size[L]) {
		eq[L] = K;
		size[K] += size[L];
	}
	else {
		eq[K] = L;
		size[L] += size[K];
	}
}

// Find root
int root(int n, vector<int>& eq) {
	int r = n, temp;
	if (eq[n] == -1) eq[n] = n;
	while (eq[r] != r) r = eq[r];
	while (eq[n] != n) {
		temp = eq[n];
		eq[n] = r;
		n = temp;
	}
	return r;
}

// Topological sort
int bfs(vector<vector<int>>& mo, vector<int>& in) {
	queue<int> q;
	int cnt = 0;

	FOR(i, mo.size()) {
		if (in[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int x : mo[n]) {
			in[x]--;
			if (in[x] == 0)
				q.push(x);
		}
		cnt++;
	}
	return cnt;
}

void chess() {
	int N, M, K, L, nsets = 0;
	char c;
	cin >> N >> M;

	// UFDS for equal players
	// Directed Graph between the UFDS for comparisons
	// Treat each UFDS as a node

	vector<int> size(N, 1); // size of union groups for joining
	vector<int> chidx(N); 	// convert from player index to set index
	vector<int> eq(N, -1); 	// UFDS
	vector<vector<int>> mo; // adjacency list (AL) for comparisons btw sets
	vector<int> in; 		// indegree array
	vector<ii> comp; 		// to store comparison queries
	while (M--) {
		cin >> K >> c >> L;
		if (c == '=') // do unions first
			un(K, L, eq, size);
		else // store comparisons first
			comp.push_back(make_pair(K, L));
	}
	
	// Count number of distinct sets
	FOR(i, N) {
		if (eq[i] == i || eq[i] == -1) {
			if (eq[i] == -1) eq[i] = i;
			chidx[i] = nsets;
			nsets++;
		}
	}
	
	// Resize AL & indeg array
	mo.resize(nsets);
	in.resize(nsets);
	
	// Process comparison queries
	for (auto i : comp) {
		// convert player root idx to set idx
		int x = chidx[root(i.first, eq)];
		int y = chidx[root(i.second, eq)];
		// store in AL
		mo[x].push_back(y);
	}

	// Calculate indegree for each node
	for (auto i : mo) {
		for (auto j : i)
			in[j]++;
	}

	// Topological sort using BFS
	// If # of nodes counted != nsets
	// then there is a cycle somewhere - inconsistent
	if (bfs(mo, in) == nsets)
		cout << "consistent";
	else
		cout << "inconsistent";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    chess();
    return 0;
}