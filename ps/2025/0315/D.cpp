#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int sol(int a, int b, int c) {
    int l = 0, r = 600000001;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a * mid * mid + b * mid + c <= 0)
            l = mid;
        else
            r = mid;
    }
    if (a * l * l + b * l + c == 0) return l;
    return -1;
}

// https://atcoder.jp/contests/abc397/tasks/abc397_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int d = 1; d * d * d <= n; d++) {
        if (n % d) continue;
        int m = n / d;
        int x = sol(3, 3 * d, d * d - m);

        if (x != -1 && x > 0) {
            cout << x + d << ' ' << x;
            return 0;
        }
    }
    cout << -1;
}