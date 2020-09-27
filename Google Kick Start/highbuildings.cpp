#include <iostream>

using namespace std;

#define FOR(i,k) for(int i=0;i<k;i++)

void hib() {
	int T, N, A, B, C, i = 1;
	cin >> T;
	while (T--) {
		cin >> N >> A >> B >> C;
		int left = A - C, right = B - C, total_left, total_right;


		

		total_left = left ? N - B : 0;
		total_right = right ? N - A - (total_left - left) : 0;

		if (C > A || C > B || left + right + C > N || total_left + total_right + C != N) {
			cout << "Case #" << i++ << ": IMPOSSIBLE" << '\n';
			continue;
		}


		cout << "Case #" << i++ << ": ";

		FOR(j, left) {
			cout << 2 << ' ';
		}

		FOR(j, total_left - left)
			cout << 1 << ' ';
		
		FOR(j, C) {
			cout << 3 << ' ';
		}

		FOR(j, total_right - right)
			cout << 1 << ' ';

		FOR(j, right) {
			cout << 2 << ' ';
		}

		cout << '\n';


	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    hib();
    return 0;
}