#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXNUM 100000

using namespace std;

void perm(int n, int m) {
	int g, curr = 0;
	char *arr;
	arr = new char[n]();
	vector<int> subseq;
	for (int i = 0; i < m; i++) {
		cin >> g;
		g--;
		arr[g] = 1;
		subseq.push_back(g);
	}
	for (auto x : subseq) {
		for (int j = curr; j < x; j++) {
			if (!arr[j]) {
				cout << j+1 << '\n';
				arr[j] = 1;
			}
		}
		cout << x + 1 << '\n';
		curr = x;
	}
	for (int i = 0; i < n; i++) {
		if (!arr[i])
			cout << i+1 << '\n';
	}
	delete[] arr;
}

void gnome() {
	int n, m;
	cin >> n >> m;
	perm(n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    gnome();
    return 0;
}