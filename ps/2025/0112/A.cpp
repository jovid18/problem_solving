#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << ((abs(a - b) % 2) ? "NO" : "YES") << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}