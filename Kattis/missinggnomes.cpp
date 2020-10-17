#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void mg() {
    int n, m, g, idx = 1;
    cin >> n >> m;
    vector<bool> b(n, false);
    queue<int> q;
    while (m--) {
        cin >> g;
        b[g-1] = true;
        q.push(g);
    }

    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (; idx <= k; ++idx) {
            if (b[idx-1]) continue;
            cout << idx << '\n';
        }
        cout << k << '\n';
            
    }

    while (idx <= n) {
        if (b[idx-1]) continue;
        cout << idx << '\n';
        ++idx;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    mg();
    return 0;
}