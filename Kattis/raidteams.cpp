#include <iostream>
#include <set>
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;


typedef tuple<int, int, int> iii;
typedef pair<int, string> is;


struct less_than_key
{
	inline bool operator() (const is& lhs, const is& rhs) const
	{
		if (lhs.first == rhs.first)
			return lhs.second < rhs.second;
		return lhs.first > rhs.first;
	}
};

void raid() {
	int N, S1, S2, S3;
	is ps;
	string name;
	set<is, less_than_key> sk1, sk2, sk3;
	map<string, iii> players;
	cin >> N;
	while (N--) {
		cin >> name >> S1 >> S2 >> S3;
		sk1.insert({ S1, name });
		sk2.insert({ S2, name });
		sk3.insert({ S3, name });
		players[name] = { S1,S2,S3 };
	}

	vector<string> team(3);

	while (sk1.size() >= 3) {
		name = sk1.begin()->second;
		team[0] = name;
		sk1.erase(*sk1.begin());
		sk2.erase({ get<1>(players[name]), name });
		sk3.erase({ get<2>(players[name]), name });

		name = sk2.begin()->second;
		team[1] = name;
		sk2.erase(*sk2.begin());
		sk3.erase({ get<2>(players[name]), name });
		sk1.erase({ get<0>(players[name]), name });
				
		name = sk3.begin()->second;
		team[2] = name;
		sk3.erase(*sk3.begin());
		sk2.erase({ get<1>(players[name]), name });
		sk1.erase({ get<0>(players[name]), name });


		sort(team.begin(), team.end());



		for (string s : team)
			cout << s << ' ';
		cout << '\n';
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    raid();
    return 0;
}