#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    while (n--) {
        char x;
        cin >> x;
        x == '-' ? a++ : b++;
    }
    if (a >= 2 && b >= 1) {
        cout << b * (a / 2) * (a - a / 2) << '\n';
    } else {
        cout << 0 << '\n';
    }
}

// https://codeforces.com/contest/2072/problem/B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}