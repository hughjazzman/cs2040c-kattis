#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

void lostmap() {
    int n, k, cnt = 0;
    cin >> n;
    vector<bool> b(n,false);
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    }
    priority_queue<iii> q;
    q.push({0,{0,0}});
    while (!q.empty()) {
        int cvf = q.top().second.first, cvt = q.top().second.second;
        int ck = q.top().first;
        q.pop();
        if (b[cvt]) continue;
        if (cnt == n) break;
        if (cvf || cvt)
            cout << cvf + 1 << ' ' << cvt + 1 << '\n';
        b[cvt] = true;
        ++cnt;
        for (int i = 0; i < n; ++i) {
            if (b[i]) continue;
            q.push({-g[cvt][i], {cvt, i}});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    lostmap();
    return 0;
}