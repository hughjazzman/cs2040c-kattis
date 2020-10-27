#include <iostream>
#include <vector>
#include <string>

using namespace std;

void epig() {
    int n, m, res = 1;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) 
        cin >> g[i];
    

    for (int i = 0; i < m; ++i) {
        bool b = true;
        for (int j = 0; j < n; ++j) {
            if (g[j][i] == '_') continue;
            b = false;
            break;
        }
        if (b)
            res++;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    epig();
    return 0;
}