#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(vector<string> &v, int r, int c) {
    v[r][c] = '#';
    for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr < 0 || nr >= v.size() || nc < 0 || nc >= v[0].size()) continue;
        if (v[nr][nc] == '#') continue;
        dfs(v, nr, nc);
    }
}

void ctst() {
    int m, n, c = 1;
    while (cin >> m >> n) {
        int res = 0;
        vector<string> v(m);
        for (int i = 0; i < m; ++i)
            cin >> v[i];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j] == '#') continue;
                res++;
                dfs(v, i, j);
            }
        }
        cout << "Case " << c++ << ": " << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ctst();
    return 0;
}