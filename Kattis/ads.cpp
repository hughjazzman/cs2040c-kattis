#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <locale>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

#define FOR(i,k) for(int i=0;i<k;i++)

void images(vector<string> & g, iiii r) {

	int i, j, k, m, k2, m2;
	bool b = true;
	for (i = r.first.second; i <= r.second.second; i++) {
		for (j = r.first.first; j <= r.second.first; j++) {
			//cout << i << ' ' << j << endl;
			if (g[i][j] == '+') {
				int i2 = i, j2 = j;
				while (j2 < r.second.first && g[i][j2 + 1] == '+') {
					j2++;
				}
				while (i2 < r.second.second && g[i2 + 1][j] == '+') {
					i2++;
				}
				
				images(g, { {j + 1, i + 1}, {j2 - 1, i2 - 1} });
			}
			// invalid character
			else if (r.first.first && r.first.second && \
				!isalnum(g[i][j]) && g[i][j] != '?' && g[i][j] != '!' && \
				g[i][j] != ',' && g[i][j] != '.' && g[i][j] != ' ') {
				b = false;
				break;
			}
		}
		if (!b) break;
	}
	if (!b) {
		for (i = r.first.second - 1; i <= r.second.second + 1; i++) {
			for (j = r.first.first - 1; j <= r.second.first + 1; j++) {
				//cout << i << ' ' << j << endl;
				g[i][j] = ' ';
			}
		}
	}


}

void ads() {
	int H, W, i = 0;
	vector<iiii> v;

	cin >> H >> W;

	vector<string> g(H);

	cin.ignore();
	FOR(j,H) {
		getline(cin, g[i++]);
	}


	
	images(g, { {0,0},{W - 1,H - 1} });

	for (string s : g)
		cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ads();

    return 0;
}