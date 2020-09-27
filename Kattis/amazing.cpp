#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

struct key_hash : public std::unary_function<iii, std::size_t>
{
	std::size_t operator()(const iii& k) const
	{
		return k.first.first ^ k.first.second ^ k.second;
	}
};

struct key_hash_ii : public std::unary_function<ii, std::size_t>
{
	std::size_t operator()(const ii& k) const
	{
		return k.first ^ k.second;
	}
};

string dirStr(int dir) {
	switch (dir) {
	case 0:
		return "up";
	case 1:
		return "right";
	case 2:
		return "down";
	case 3:
		return "left";
	default:
		return "";
	}
}

ii nextState(ii pos, int dir) {
	int r = pos.first, c = pos.second;
	switch (dir) {
	case 0:
		return { r + 1,c };
	case 1:
		return { r,c + 1 };
	case 2:
		return { r - 1, c };
	case 3:
		return { r,c - 1 };
	default:
		return pos;
	}
}



void amaz() {
	string s, path;
	ii sq = { 0,0 }, n_sq = nextState(sq, 0);
	int dir = 0;
	
	unordered_set<iii, key_hash> sa; // check if state action has been
	unordered_set<ii, key_hash_ii> st;
	st.insert(sq);
	cout << dirStr(0) << '\n' << flush;
	while (cin >> s) {
		if (s == "solved" || s == "wrong") break;

		sa.insert({ sq,dir });

		if (s == "ok") {
			sq = n_sq;
			st.insert(sq);
		}
			
		
		bool found = false;

		for (int i = 0; i < 4; i++) {
			n_sq = nextState(sq, i);
			if (st.count(n_sq) || sa.count({ sq, i })) continue;
			found = true;
			cout << dirStr(i) << '\n' << flush;
			dir = i;
			break;
		}

		if (found) continue;

		for (int i = 0; i < 4; i++) {
			if (sa.count({ sq, i })) continue;
			found = true;
			n_sq = nextState(sq, i);
			cout << dirStr(i) << '\n' << flush;
			dir = i;
			break;
		}
		if (!found) {
			cout << "no way out\n";
			break;
		}
		
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    amaz();
    return 0;
}