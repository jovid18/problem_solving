#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    if (k < 0) {
        k *= -1;
    }

    if (n * p < k) {
        cout << -1 << '\n';
    } else {
        cout << ceil((double)k / p) << '\n';
    }
}

// https://codeforces.com/contest/2072/problem/A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}