#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int T, E, N, s;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> E >> N;
        int r = 0;
        deque<int> d;
        while (N--) {
            cin >> s;
            d.push_back(s);
        }
        sort(d.begin(), d.end());
        
        int used = 0;
        while (!d.empty()) {
            while (E > d.front() && !d.empty()) {
                if (used) {
                    // Not enough honour
                    if (r < used) {
                        used == -1;
                        break;
                    }
                    used = 0;
                    // Recruit
                    r -= 1;
                }
                // Dance
                E -= d.front();
                d.pop_front();
                r += 1;
            }
            if (d.empty() || used == -1) break;
            E += d.back();
            d.pop_back();
            used += 1;
        }

        cout << "Case #" << i << ": " << r << endl;
    }
}