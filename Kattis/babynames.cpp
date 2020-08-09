#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<string, null_type, std::less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


void baby() {
	int cmd, gend, n, n1, n2;
	string s1, s2;
	ordered_set st1, st2;

	while (cin >> cmd) {
		switch (cmd) {
		case 0: return;
		case 1:
			cin >> s1 >> gend;
			gend--;
			if (gend)
				st2.insert(s1);
			else
				st1.insert(s1);
			break;
		case 2: {
			cin >> s1;
			auto it = st1.find(s1);
			if (it != st1.end())
				st1.erase(it);
			else
				st2.erase(st2.find(s1));
			break;
		}
		case 3: {
			cin >> s1 >> s2 >> gend;
			if (gend == 0 || gend == 1) {
				auto low1 = st1.order_of_key(s1);
				auto upp1 = st1.order_of_key(s2);
				n1 = upp1 - low1;

			}
			if (gend == 0 || gend == 2) {
				auto low2 = st2.order_of_key(s1);
				auto upp2 = st2.order_of_key(s2);
				n2 = upp2 - low2;
			}

			if (gend == 0)
				n = n1 + n2;
			else if (gend == 1)
				n = n1;
			else
				n = n2;

			cout << n << '\n';
			break;
		}
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    baby();

    return 0;
}