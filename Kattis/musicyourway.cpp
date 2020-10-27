#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <unordered_map>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;

    vector<string> h;
    unordered_map<string, int> mp;
    int m, n, col = 0;
    getline(cin, s);
    istringstream iss(s);
    while (iss >> s) {
        mp[s] = col++;
        h.push_back(s);
    }
    cin >> m;
    
    vector<vector<string>> v(m, vector<string>(col));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> v[i][j];
        }
    }
    
    cin >> n;
    while (n--) {
        cin >> s;
        int p = mp[s];
        stable_sort(v.begin(), v.end(), [&](const std::vector<string>& a, const std::vector<string>& b) {
            return a[p] < b[p];
        });
        for (string t : h)
            cout << t << ' ';
        cout << '\n';
        for (auto x : v) {
            for (string t : x)
                cout << t << ' ';
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}