#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, y;
    cin >> x >> y;
    if (y == x + 1) {
        cout << "Yes\n";
    } else if (y == x) {
        cout << "No\n";
    } else if (x - y > 0 && (x - y + 1) % 9 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}