#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,k) for(int i=0;i<k;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, R, C, x = 1;
    string s;
    cin >> T;
    while (T--) {
        cin >> R >> C; cin.ignore();
        vector<string> v;
        FOR(i, R) {
            getline(cin, s);
            v.push_back(s);
        }
        cout << "Test " << x++ << '\n';
        for (int i = R-1; i >= 0; i--) {
            for (int j = C-1; j >= 0; j--)
                cout << v[i][j];
            cout << '\n';
        }

        
    }

    return 0;
}