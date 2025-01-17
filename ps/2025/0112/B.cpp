#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    vector<int> a, b;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    int cnt = 0;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            cnt++;
            idx = i;
        }
    }
    if (cnt > 1) {
        cout << "NO\n";
    } else if (cnt == 0) {
        cout << "YES\n";
    } else {
        int diff = b[idx] - a[idx];
        for (int i = 0; i < n; ++i) {
            a[i] -= diff;
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (i == idx) continue;
            if (a[i] < b[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
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