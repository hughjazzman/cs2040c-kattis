#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll merge(vector<int>& v, vector<int>& L, vector<int>& R) {
    int i = 0, j = 0, cnt = 0;
    while (i < L.size() || j < R.size()) {
        if (i == L.size()) {
            v[i + j] = R[j];
            j++;
        }
        else if (j == R.size()) {
            v[i + j] = L[i];
            i++;
        }
        else if (L[i] <= R[j]) {
            v[i + j] = L[i];
            i++;
        }
        else {
            v[i + j] = R[j];
            cnt += L.size() - i;
            j++;
        }
    }
    return cnt;
}


ll invCount(vector<int>& v) {
    if (v.size() < 2) return 0;

    int m = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + m);
    vector<int> right(v.begin() + m, v.end());

    return invCount(left) + invCount(right) + merge(v, left, right);
}

void bs() {
    int N, k;
    cin >> N;
    vector<int> v1(N), v2(N);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i)
                cin >> v2[j];
            else
                cin >> v1[j];
        }
    }

    if (~(invCount(v1) ^ invCount(v2)) & 1)
        cout << "Possible";
    else
        cout << "Impossible";
        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bs();
    return 0;
}