#include <iostream>

using namespace std;


void alien() {
	int T, K, A, c, pre, res, i = 0, hi, low, incr;
	cin >> T;
	while (T--) {
		cin >> K;
		hi = 0, low = 0;
		c = 0;
		pre = 0;
		res = 0;
		incr = 0;
		cin >> pre;
		while (--K) {
			cin >> A;

			if (incr == 1 && A < pre || incr == -1 && A > pre)
				c = 0; hi = 0; low = 0;
			if (A > pre) {
				incr = 1;
				c++;
			}
			else if (A < pre) {
				incr = -1;
				c--;
			}

			hi = c > hi ? c : hi;
			low = c < low ? c : low;

			if (hi - low > 3) {
				res++;
				c = 0; hi = 0; low = 0;
				incr = 0;
			}
			pre = A;
			
		}
		cout << "Case #" << ++i << ": " << res << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    alien();

    return 0;
}