#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void record() {
	int T, N, V, c, res, prev, i = 1;
	vector<bool> g;
	cin >> T;

	while (T--) {
		g.clear();
		cin >> N;
		c = -1;
		prev = -1;
		res = 0;
		while (N--) {
			cin >> c;
			if (g.empty()) {
				g.push_back(true);
				prev = c;
			}
			else if (*g.rbegin()) {
				if (c >= prev) {
					g.back() = false;
					g.push_back(c > prev);
					prev = c;
				}
				else
					g.push_back(false);

			}
			else if (c > prev) {
				g.push_back(true);
				prev = c;
			}
			else
				g.push_back(false);

		}
		//for (bool b : g) cout << b << endl;
		cout << "Case #" << i++ << ": " << count(g.begin(), g.end(), true) << '\n';
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    record();

    return 0;
}