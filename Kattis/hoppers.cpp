#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &g, vector<int> &b, int n, int i) {
    if (b[n] != -1) return true;
    b[n] = i;
    bool bi = true;
    for (int m : g[n]) {
        if (b[m] == -1)
            bi &= dfs(g, b, m, !i);
        else if (b[m] == i)
            bi = false;
    }
    return bi;
}

void hopp() {
    int N, M, u, v, nc = -1;
    bool bi = true;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<int> b(N, -1);
    while (M--) {
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < N; ++i) {
        if (b[i] != -1) continue;
        nc++; //num components
        bi &= dfs(g, b, i, 0);
    }
    if (bi) nc++;
    cout << nc;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    hopp();
    return 0;
}