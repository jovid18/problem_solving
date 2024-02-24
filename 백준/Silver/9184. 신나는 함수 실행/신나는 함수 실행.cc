#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c;
int DP[51][51][51];
int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (DP[a][b][c] != -1) {
        return DP[a][b][c];
    }
    if (a > 20 || b > 20 || c > 20) {
        return DP[a][b][c] = w(20, 20, 20);
    }
    if (a < b && b < c) {
        return DP[a][b][c] =
                   w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return DP[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                         w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 50; ++i) {
        for (int j = 1; j <= 50; ++j) {
            for (int k = 1; k <= 50; ++k) {
                DP[i][j][k] = -1;
            }
        }
    }
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)
             << '\n';
    }
}