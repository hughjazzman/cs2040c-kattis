// CS2040/C Past Finals G

#include <vector>
#include <iostream>
#include <queue>

#define FOR(i,k) for(int i=0;i<k;i++)

using namespace std;

int topo(vector<bool> & lab, vector<vector<int>> & dep, vector<int> in, bool st) {
	// queues for each lab
	queue<int> q1, q2;
	int cnt = 0;
	// add all 0 indegrees to queue
	FOR(i, in.size()) {
		if (in[i] == 0) {
			if (lab[i])
				q1.push(i);
			else
				q2.push(i);
		}
	}

	while (!q1.empty() || !q2.empty()) {
		int n;
		// switch queue once empty
		if (st && q1.empty() || !st && q2.empty()) {
			st = !st;
			cnt++; //switch queue means switch lab
		}
			
		if (st) {
			n = q1.front();
			q1.pop();
		}
		else {
			n = q2.front();
			q2.pop();
		}

		for (int i : dep[n]) {
			in[i]--;
			if (in[i] == 0) {
				if (lab[i])
					q1.push(i);
				else
					q2.push(i);
			}
		}

	}
    return cnt;
}

void test(int n, int m) {
	int labn, i, j;
	// stores lab num of each stage
	// true if lab 1, false if lab 2
	vector<bool> lab;
	// dependencies as a DAG
	// connected iff i done before j
	vector<vector<int>> dep(n);
	vector<int> in(n, 0); // indegree array

	while (n--) {
		cin >> labn;
		lab.push_back(labn == 1);
	}

	while (m--) {
		cin >> i >> j;
		dep[--i].push_back(--j);
		// calculate indegrees
		in[j]++; 
	}

	int sw = min(topo(lab, dep, in, true), topo(lab, dep, in, false));
	cout << sw << endl;
}

void cons() {
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		test(n, m);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cons();
    return 0;
}