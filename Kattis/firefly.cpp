#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void ff() {
    int N, H, s, min = INT_MAX, cnt = 0, num;
    bool b = true;
    cin >> N >> H;
    vector<int> uh(H,0), dh(H,0);
    for (int i = 0; i < N; ++i) {
        cin >> s;
        --s;
        if (b)
            ++uh[s];
        else
            ++dh[s];
        b ^= true;
    }    

    for (int i = H - 2; i >= 0; --i) {
        uh[i] += uh[i+1];
        dh[i] += dh[i+1];
    }

    for (int i = 0; i < H; ++i) {
        num = uh[i] + dh[H-i-1];
        if (num < min) {
            min = num;
            cnt = 1;
        } else if (num == min)
            ++cnt;
    }

    cout << min << ' ' << cnt;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ff();
    return 0;
}