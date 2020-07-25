#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define FOR(i,k) for(int i=0;i<k;i++)

void p1() {
	int N, t, m1, m2;
	ll r = 0;
	vector<int> a;
	
	string s;
	cin >> N >> t;
	vector<bool> v(N, false);

	switch (t) {
	case 1:
		cout << 7;
		break;
	case 2:
		cin >> m1 >> m2;
		if (m1 > m2)
			cout << "Bigger";
		else if (m1 == m2)
			cout << "Equal";
		else
			cout << "Smaller";
		break;	
	case 3:
		FOR(i, 3) {
			cin >> m1;
			a.push_back(m1);
		}
		sort(a.begin(), a.end());

		cout << a[1];
		break;

	case 4:
		while (N--) {
			cin >> m1;
			r += m1;
		}

		cout << r;
		break;
		
	case 5:
		while (N--) {
			cin >> m1;
			if (m1 % 2 == 0)
				r += m1;
		}
		cout << r;
		break;	
	case 6:
		
		while (N--) {
			cin >> m1;
			m1 %= 26;
			s.push_back(m1 + 'a');
		}
		cout << s;
		break;
	case 7:
		FOR(i, N) {
			cin >> m1;
			a.push_back(m1);
		}

		while (1) {
			int nn = a[r];
			if (nn < N - 1) {
				if (v[nn]) {
					cout << "Cyclic";
					break;
				}
				v[r] = true;
				r = nn;
				continue;
			}
			if (nn >= N)
				cout << "Out";
			else
				cout << "Done";
			break;
		}

		break;
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p1();

    return 0;
}