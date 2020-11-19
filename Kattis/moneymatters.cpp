#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void monmat() {
    int n, m, o, x, y;
    cin >> n >> m;
    vector<int> amt(n);
    vector<bool> b(n,false);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> amt[i];
    }
    while (m--) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (b[i]) continue;
        int bal = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cv = q.front();
            q.pop();
            if (b[cv]) continue;
            bal += amt[cv];
            b[cv] = true;
            for (int j : g[cv]) {
                if (b[j]) continue;
                q.push(j);
            }
        }
        if (bal != 0) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << "POSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    monmat();
    return 0;
}