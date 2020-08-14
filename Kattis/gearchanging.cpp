#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void gear() {
	int N, M, P, C, D;
	vector<int> cr;
	vector<double> fr;
	cin >> N >> M >> P;
	while (N--) {
		cin >> C;
		cr.push_back(C);
	}
	while (M--) {
		cin >> D;
		for (int i : cr)
			fr.push_back((double)i / (double)D);
	}
	sort(fr.begin(), fr.end());

	double r;
	for (int i = 1; i < fr.size(); i++) {
		r = ((fr[i] / fr[i - 1]) - 1) * 100;
		if (r > P) {
			cout << "Time to change gears!";
			return;
		}
	}
	cout << "Ride on!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    gear();
    return 0;
}