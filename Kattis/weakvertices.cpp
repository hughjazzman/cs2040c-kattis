#include <iostream>

#define N 20

using namespace std;

void mul(int mat1[][N], int mat2[][N], int res[][N], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            res[i][j] = 0;
            for (k = 0; k < n; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

void wkv() {
    int mat[N][N], tmp[N][N], res[N][N];
    int n;
    while (cin >> n) {
        if (n == -1) break;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
                cin >> mat[i][j];
        }
        mul(mat, mat, tmp, n);
        mul(tmp, mat, res, n);
        for (int i = 0; i < n; ++i) {
            if (res[i][i] == 0)
                cout << i << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    wkv();
    return 0;
}