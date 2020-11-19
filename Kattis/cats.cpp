#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

void cats() {
    int T, M, C, E, i, j, D;
    cin >> T;
    while (T--) {
        cin >> M >> C;
        M -= C; // give cats all milk, concentrate on spill
        if (M < 0) {
            cout << "no";
            continue;
        }
        vector<vector<int>> g(C,vector<int>(C));
        vector<bool> b(C, false);
        E = C*(C-1)/2;
        while (E--) {
            cin >> i >> j >> D;
            g[i][j] = D;
            g[j][i] = D;
        }
        priority_queue<ii, vector<ii>, greater<ii>> q;
        q.push({0,0});
        bool f = false;
        int cnt = 0;
        while (!q.empty()) {
            int cv = q.top().second, ck = q.top().first;
            q.pop();
            if (b[cv]) continue;
            if (cnt == C) break;
            b[cv] = true;
            ++cnt;
            M -= ck;
            for (int i = 0; i < C; ++i) {
                if (b[i]) continue;
                q.push({g[cv][i], i});
            }
            
            if (M >= 0) continue;
            f = true;
            break;
        }
        if (f)
            cout << "no";
        else
            cout << "yes";
        cout << '\n';
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cats();
    return 0;
}