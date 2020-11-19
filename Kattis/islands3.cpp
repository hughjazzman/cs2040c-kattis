#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<string> &g, int r, int c) {
    g[r][c] = 'W';
    for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr < 0 || nr >= g.size() || nc < 0 || nc >= g[0].size()) continue;
        if (g[nr][nc] == 'W') continue;
        dfs(g, nr, nc);
    }
}

void isl() {
    int r,c,n=0;
    cin >> r >> c;
    vector<string> g(r);
    for (int i = 0; i < r; ++i) 
        cin >> g[i];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] == 'W' || g[i][j] == 'C') continue;
            dfs(g,i,j);
            ++n;
        }
    }
    cout << n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    isl();
    return 0;
}