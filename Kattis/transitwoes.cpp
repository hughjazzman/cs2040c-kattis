#include <iostream>
#include <vector>

using namespace std;

void trw() {
	int s, t, n, d, b, c;
	vector<int> vd, vb, vc;
	cin >> s >> t >> n;

	for (int i = 0; i <= n; i++) {
		cin >> d;
		vd.push_back(d);
	}
	for (int i = 0; i < n; i++) {
		cin >> b;
		vb.push_back(b);
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		vc.push_back(c);
	}

	for (int i = 0; i < n; i++) {
		s += vd[i];
		if (s % vc[i])
			s = ((s / vc[i]) + 1) * vc[i];
		s += vb[i];
		if (s > t) break;
	}
	s += vd[n];
	if (s > t)
		cout << "no";
	else
		cout << "yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    trw();
    return 0;
}