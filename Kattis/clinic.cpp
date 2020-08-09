#include <iostream>
#include <set>
#include <string>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, string> is;

struct compare {
	bool operator() (const is& lhs, const is& rhs) const {
		if (lhs.first == rhs.first)
			return lhs.second < rhs.second;
		return lhs.first > rhs.first;
	}
};

void clinic() {
	ll N, K, Q, T, S;
	string M;
	set<is, compare> st;
	map<string, ll> mp;
	cin >> N >> K;

	while (N--) {
		cin >> Q;
		switch (Q) {
		case 1:
			cin >> T >> M >> S;
			st.insert({ S - K * T, M });
			mp[M] = S - K * T;
			break;
		case 2:
			cin >> T;
			if (st.empty())
				cout << "doctor takes a break\n";
			else {
				cout << st.begin()->second << '\n';
				st.erase(st.begin());
			}
			break;
		case 3:
			cin >> T >> M;
			st.erase({ mp[M],M });
			break;

		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    clinic();
    return 0;
}