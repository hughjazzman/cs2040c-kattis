#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &v, int n, int i) {
    if (v[n] != -1) return;
    v[n] = i;
    for (int m : g[n]) {
        if (v[m] != -1) continue;
        dfs(g, v, m, !i);
    }
}

void mlk() {
    int N, a, b;
    cin >> N;
    vector<vector<int>> g(N);
    vector<int> v(N, -1), q(N-1);
    for (int i = 1; i < N; ++i) {
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        q[i-1] = a;
    }
    dfs(g, v, 0, 0);
    for (int i : q)
        cout << v[i] << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    mlk();
    return 0;
}