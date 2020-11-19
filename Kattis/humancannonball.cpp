#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cfloat>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<double, int> di;
typedef pair<int, ii> iii;

double edist(dd lhs, dd rhs) {
    double dx = lhs.first - rhs.first;
    double dy = lhs.second - rhs.second;
    return sqrt(dx*dx+dy*dy);
}

void humcan() {
    double Xs, Ys, Xd, Yd, X, Y;
    int n;
    // priority_queue<iii> q;
    set<di> q;

    cin >> Xs >> Ys >> Xd >> Yd >> n;

    vector<dd> v(n+2);
    vector<bool> b(n+2,false);
    vector<double> d(n+2, DBL_MAX);
    d[0] = 0;
    v[0] = {Xd, Yd}; v[n+1] = {Xs, Ys};

    for (int i = 1; i <= n; ++i) {
        cin >> X >> Y;
        v[i] = {X,Y};
    }

    // q.push({0,{0,0}});
    q.insert({0,0});

    while (!q.empty()) {
        int cv = q.begin()->second;
        if (cv == n + 1) break;
        b[cv] = true;
        q.erase(q.begin());
        for (int i = 1; i <= n+1; ++i) {
            if (b[i]) continue;
            double cd = d[i], clen = edist(v[i],v[cv]);
            if (i != n + 1) {
                if (clen > 50)
                    clen = 2 + (clen-50)/5;
                else
                    clen = min(clen/5, 2 + (50-clen)/5);
            } else
                clen /= 5;
                
            if (cd > d[cv] + clen) {
                q.erase({cd, i});
                d[i] = d[cv] + clen;
                q.insert({d[i],i});
            }
        }
    }
    cout << d[n+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    humcan();
    return 0;
}