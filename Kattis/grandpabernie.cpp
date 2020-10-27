#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void gpb() {
    int n, y, q, k;
    string s;
    unordered_map<string, vector<int>> mp;
    cin >> n;
    while (n--) {
        cin >> s >> y;
        mp[s].push_back(y);
    }
    for (auto &x : mp) 
        sort(x.second.begin(), x.second.end());
    cin >> q;
    while (q--) {
        cin >> s >> k;
        cout << mp[s][k-1] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    gpb();
    return 0;
}