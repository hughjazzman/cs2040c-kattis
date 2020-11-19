#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void malro() {
    ll T, x1, y1, x2, y2, dx, dy, dd;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2;
        dx = abs(x1 - x2);
        dy = abs(y1 - y2);
        dd = abs(dx - dy);
        if (dd % 2) --dd;
        cout << dx + dy + dd << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    malro();
    return 0;
}