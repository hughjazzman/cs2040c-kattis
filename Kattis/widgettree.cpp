#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef unordered_set<int> uos;
typedef vector<uos> vuos;

uos vis;
ll m;

ll dfs(vuos &g, vi &nc, vuos &ic, int s, vvi &gn) {
    vis.insert(s);
    ll numc = 1;
    for (int i : g[s]) {
        // cout << i << endl;
        // cycle detected
        // visited before but not set yet
        if (vis.count(i) && nc[i] == -1) 
            return -1;
        // add to isChild
        ic[s].insert(i);
        ll cnumc;
        cnumc = nc[i] == -1 ?  dfs(g, nc, ic, i, gn) : nc[i];
        if (cnumc == -1) 
            return -1;
        numc += (gn[s][i] * (cnumc % m)) % m;
        // add child's child
        for (int j : ic[i])
            ic[s].insert(j);
    }
    nc[s] = numc % m;
    return numc % m;
}

ll dfsq(vuos &g, vi &nc, vuos &ic, int s, uos &que, vi &val, vvi &gn) {
    ll res = 1;
    for (int i : g[s]) {
        if (que.count(i)) {
            res += (gn[s][i] * (nc[i] % m)) % m; 
            continue;
        }
        ll cval;
        if (val[i] > 0) {
            res += (gn[s][i] * (val[i] % m)) % m;
            continue;
        }
        if (val[i] == 0) continue;
        if (val[i] == -1) {
            for (int j : que) {
                if (!ic[i].count(j)) continue;
                val[i] = 1;
                break;
            }
            if (val[i] == -1)
                val[i] = 0;
        }
        if (val[i] == 0) continue;


        cval = val[i] == 1 ? dfsq(g, nc, ic, i, que, val, gn) : val[i];
        res += (gn[s][i] * (cval % m)) % m;
    }
    // cout << s << ' ' << res << endl;
    val[s] = res % m;
    return res % m;
}

void widt() {
    ll n, c, d, q, t, x, y;
    cin >> n >> m;
    //vvi g(n);
    vuos g(n);
    vvi gn(n, vi(n,1));
    
    vi nchild(n, -1);
    // vvi vst(n);
    vuos vst(n);

    // parse
    for (int i = 0; i < n; ++i) {
        cin >> c;
        while (c--) {
            cin >> d;
            //g[i].push_back(d);
            if (g[i].count(d))
                gn[i][d]++;
            g[i].insert(d);
        }
    }

    ll w0 = dfs(g, nchild, vst, 0, gn);

    if (w0 == -1) {
        cout << "Invalid";
        return;
    }

    cin >> q >> t;

    if (t) {
        cout << "Valid";
        return;
    }
    
    cout << w0 << '\n';

    while (q--) {
        vi values(n, -1);
        uos que;
        cin >> x;
        while (x--) {
            cin >> y;
            if (y == 0) {
                que.insert(y);
                string s;
                getline(cin, s);
                break;
            }
            if (vst[0].count(y))
                que.insert(y);
        }
        if (que.empty())
            cout << 0 << '\n';
        else if (que.count(0))
            cout << nchild[0] << '\n';
        else
            cout << dfsq(g, nchild, vst, 0, que, values, gn) << '\n';
        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    widt();
    return 0;
}