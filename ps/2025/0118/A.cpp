#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, d, e;
    cin >> a >> b >> d >> e;
    int ans1 = 1;
    int ans2 = 1;
    int ans3 = 1;

    int x1 = a + b;
    if (b + x1 == d) {
        ans1++;
    }

    if (x1 + d == e) {
        ans1++;
    }

    int x2 = d - b;
    if (a + b == x2) {
        ans2++;
    }
    if (x2 + d == e) {
        ans2++;
    }

    int x3 = e - d;
    if (a + b == x3) {
        ans3++;
    }
    if (b + x3 == d) {
        ans3++;
    }

    cout << max({ans1, ans2, ans3}) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}