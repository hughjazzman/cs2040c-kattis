#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void phm() {
    string s, s2;
    double d;
    int i;

    while (getline(cin, s)) {
        istringstream iss(s);
        vector<string> v;
        d = 0;
        i = 0;

        while (iss >> s2) {
            if (isalpha(s2[0]))
                v.push_back(s2);
            else {
                d += stod(s2);
                i++;
            }
                
        }
        cout << setprecision(6) << fixed << d / i << ' ';
        for (string s3 : v)
            cout << s3 << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    phm();
    return 0;
}