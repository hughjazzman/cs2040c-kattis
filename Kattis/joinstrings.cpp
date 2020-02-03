#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <istream>

using namespace std;


int main() {
    int n, x = 1, y;
    string temp;
    cin >> n;
    vector<list<string>> str(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        str[i].push_back(temp);
    }

    for (int j = 0; j < n - 1; j++) {
        cin >> x >> y;
        str[x-1].splice(str[x-1].end(), str[y-1]);
    }

    for (auto k : str[x - 1])
        cout << k;
    return 0;
 
}