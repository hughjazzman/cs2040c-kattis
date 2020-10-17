#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, string> is;


void dr() {
	int N, c, lvl;
	ii cat, new_cat;
	string name;
	set<is> st;
	unordered_map<string, ii> mp;
	cin >> N;
	while (N--) {
		cin >> c;
		switch (c) {
		case 0:
			cin >> name >> lvl;
			st.insert({ {lvl, N}, name });
			mp[name] = { lvl, N };
			break;		
		case 1:
			cin >> name >> lvl;
			cat = mp[name];
			new_cat = { cat.first + lvl, cat.second };
			st.erase({ cat, name });
			st.insert({ new_cat , name });
			mp[name] = new_cat;
			break;
		case 2:
			cin >> name;
			cat = mp[name];
			st.erase({ cat, name });
			break;		
		case 3:
			if (st.empty())
				cout << "The clinic is empty";
			else
				cout << st.rbegin()->second;
			cout << endl;
			break;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dr();
    return 0;
}