#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

void bstt() {
    int n, k;
    ll r = 0;
    set<int> st;
    cin >> n;
    vector<int> v(n);
    while (n--) {
        cin >> k;
        --k;
        if (st.empty()) {
            st.insert(k);
            v[k] = 0;
            cout << r << '\n';
            continue;
        }
        auto lw = st.lower_bound(k);

        int inhi = -1, inlo = -1;

        if (lw != st.end())
            inhi = *lw;

        
        if (lw != st.begin())
            --lw;

        inlo = *lw;

        int hhi = -1, hlo = -1;

        if (inhi != -1)
            hhi = v[inhi];
        if (inlo != -1)
            hlo = v[inlo];


        v[k] = hhi > hlo ? hhi + 1 : hlo + 1;
        r += v[k];
        cout << r << '\n';
        st.insert(k);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bstt();
    return 0;
}