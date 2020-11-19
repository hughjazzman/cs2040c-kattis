#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

void uniz() {
    ll R, C, F, S, G, K, ri, ci, rs, cs, D, f, Ti;
    cin >> R >> C >> F >> S >> G;
    vector<int> tval(F);
    vector<vector<ii>> fac(F);
    vector<vector<iii>> stu(F);
    vector<vector<ll>> diff(F);
    vector<ll> steps(F);
    for (int j = 0; j < F; ++j) {
        cin >> K;
        for (int i = 0; i < K; ++i) {
            cin >> ri >> ci;
            fac[j].push_back({ri,ci});
        }
        sort(fac[j].begin(), fac[j].end());
    }
    while (S--) {
        cin >> rs >> cs >> D >> f;
        --f;
        stu[f].push_back({D, {rs,cs}});
    }
    for (int i = 0; i < F; ++i) {
        cin >> Ti;
        tval[i] = Ti;
    }
    
    for (auto &x : stu)
        sort(x.begin(), x.end());
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < stu[i].size(); ++j) {
            ii stupos = stu[i][j].second, bpos = fac[i][j];
            int cdiff = abs(stupos.first - bpos.first) 
                    + abs(stupos.second - bpos.second);
            diff[i].push_back(cdiff);
        }
        sort(diff[i].begin(), diff[i].end());
        steps[i] = accumulate(diff[i].begin(), diff[i].begin() + tval[i], 0LL);
    }

    sort(steps.begin(), steps.end());

    cout << accumulate(steps.begin(), steps.begin() + G, 0LL);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    uniz();
    return 0;
}