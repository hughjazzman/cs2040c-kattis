#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void lar() {
	int T, N, A, A_pre, diff, cnt, hi_cnt, i = 1;
	cin >> T;
	while (T--) {
		diff = INT_MAX, cnt = 0, hi_cnt = 0;
		cin >> N >> A_pre;
		while (--N) {
			cin >> A;
			if (A - A_pre == diff) {
				cnt++;
			}
				
			else {
				diff = A - A_pre;
				cnt = 2;
			}
			A_pre = A;
			if (cnt > hi_cnt)
				hi_cnt = cnt;
		}

		cout << "Case #" << i++ << ": " << hi_cnt << '\n';

	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    lar();
    return 0;
}