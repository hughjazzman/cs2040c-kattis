#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}, {-1,-1}, {-1,1}, {1,1}, {1,-1}};



bool dfs(vector<string> &g, int r, int c, int n) {
    char st = g[r][c];
    g[r][c] = 'O';
    for (int i = 0; i < 8; ++i) {
        
        int nr = r + dir[i][0], nc = c + dir[i][1];
        bool b;
        for (int j = 1; j < n; ++j) {
            b = false;
            if (nr < 0 || nr >= g.size() || nc < 0 || nc >= g[0].size()) break;
            if (g[nr][nc] != st) break;
            nr = nr + dir[i][0], nc = nc + dir[i][1];
            b = true;
        }
        if (b) return true;
    }
    return false;
}

void cnn() {
    int x, y, n;
    char c;
    cin >> x >> y >> n;
    vector<string> g(x);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> c;
            g[i].push_back(c);
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (g[i][j] == 'O') continue;
            c = g[i][j];
            bool b = dfs(g, i, j, n);
            if (b) {
                if (c == 'R')
                    cout << "RED";
                else
                    cout << "BLUE";
                cout << " WINS";
                return;
            }

        }
    }
    cout << "NONE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cnn();
    return 0;
}