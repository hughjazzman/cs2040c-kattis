#include <iostream>

using namespace std;

typedef long long ll;

void thanos() {
	ll t, p, r, f, i;
	cin >> t;
	while (t--) {
		i = 0;
		cin >> p >> r >> f;
		while (p <= f) {
			p *= r;
			i++;
		}
		cout << i << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    thanos();
    return 0;
}