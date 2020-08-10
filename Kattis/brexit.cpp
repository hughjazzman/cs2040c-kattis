#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void brexit() {
	int C, P, X, L, A, B, u;
	cin >> C >> P >> X >> L;
	if (X == L) {
		cout << "leave";
		return;
	}

	--X; --L;
	vector<vector<int>> g(C);
	vector<int> in(C, 0), in0(C, 0);
	vector<bool> vis(C, false);
	queue<int> q;

	// parse edges
	while (P--) {
		cin >> A >> B;
		--A; --B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	// calculate indegrees
	for (auto i : g) {
		for (int j : i) {
			in[j]++;
			in0[j]++;
		}

	}


	// necessary to check that a country leaves
	// before iterating through neighbours
	// otherwise, double counting occurs
	vis[L] = true;
	for (int i : g[L]) {
		in[i]--;
		q.push(i);
	}

	while (!q.empty()) {
		u = q.front();
		q.pop();

		if (vis[u]) continue;

		if (in[u] <= in0[u] / 2) {
			if (u == X) {
				cout << "leave";
				return;
			}
			vis[u] = true;
			for (int i : g[u]) {
				in[i]--;
				q.push(i);
			}
		}
	}
	cout << "stay";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    brexit();
    return 0;
}