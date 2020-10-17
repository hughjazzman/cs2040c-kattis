#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

void gcpc() {
    int n, m, t, p, r = 1, cn, cp;
    priority_queue<iii, vector<iii>, greater<iii>> q;
    cin >> n >> m;
    vector<bool> b(n, false);
    vector<ii> s(n, {0,0});
    while (m--) {
        cin >> t >> p;
        --t;
        cn = s[t].first;
        cp = s[t].second;
        s[t] = {cn + 1, cp - p};
        if (t && s[t] > s[0]) {
            q.push({s[t], t});
            if (!b[t]) {
                r++;
                b[t] = true;
            }
        }
        
        while (t == 0 && !q.empty()) {
            iii tp = q.top();
            ii cs = tp.first;
            int ct = tp.second;
            if (cs > s[0]) break; // lowest score above team 1
            q.pop();

            if (s[ct] != cs) continue; // lazily deleted
            
            b[ct] = false;
            r--;
            
        }
        cout << r << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    gcpc();
    return 0;
}