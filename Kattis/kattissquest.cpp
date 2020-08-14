#include <iostream>
#include <utility>		// pair
#include <string>		// string
#include <set>			// set
#include <functional>	// greater
#include <climits>		// INT_MAX

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;

void quest() {
	ll N, E, G, X, r;
	string s;
	set<iii, greater<iii>> st;
	cin >> N;

	while (N--) {
		
		cin >> s;
		if (s == "add") {
			cin >> E >> G;
			st.insert({ {E,G}, N });
		}
		else {
			r = 0;
			cin >> X;
			auto it = st.lower_bound({ {X, INT_MAX}, INT_MAX });
			
			while (it != st.end()) {
				if (X < it->first.first) {
					it++; 
					continue;
				}
				X -= it->first.first;
				r += it->first.second;
				st.erase(it);
				it = st.lower_bound({ {X, INT_MAX}, INT_MAX });
			}
			
			cout << r << '\n';
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    quest();
    return 0;
}