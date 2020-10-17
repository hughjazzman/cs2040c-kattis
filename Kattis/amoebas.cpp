#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<string> &g, int r, int c, int m, int n, int dir[][2]) {
    g[r][c] = '.';
    for (int i = 0; i < 8; ++i) {
        int n_r = r + dir[i][0], n_c = c + dir[i][1];
        if (n_r < 0 || n_r >= m || n_c < 0 || n_c >= n) continue;
        if (g[n_r][n_c] == '.') continue;
        return dfs(g, n_r, n_c, m, n, dir);
    }
}

void amoebas() {
    int m, n, tot = 0;
    int dir[][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1,-1},{1,0},{1,1}};
    cin >> m >> n; cin.ignore();
    vector<string> g(m);
    for (int i = 0; i < m; ++i)
        getline(cin, g[i]);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == '.') continue;
            
            dfs(g, i, j, m, n, dir);
            tot++;

        }
    }

    cout << tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    amoebas();
    return 0;
}