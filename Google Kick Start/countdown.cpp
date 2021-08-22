#include <iostream>

using namespace std;

int main() {
    int T, N, K, a;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K;
        int r = 0; //res
        int ci; // current int
        bool c = false; // whether to check next
        while (N--) {
            cin >> a;
            if (a == K) {
                c = true;
                ci = a;
            } else if (!c) {
                continue;
            } else if (a == 1 && ci == 2) {
                r += 1;
                c = false;
            } else if (a == ci - 1) {
                ci = a;
            } else {
                c = false;
            }
        }
        cout << "Case #" << i << ": " << r << endl;
    }
    
}